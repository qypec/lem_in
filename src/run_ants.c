/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:42:51 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/10/14 13:20:28 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

typedef struct	s_way
{
	char		*room;
	size_t		ant;
}				t_way;

typedef struct	s_ways
{
	t_way		*way;
	size_t		length;
	int			ants_q;
	size_t		ants_end;
	size_t		ants;
}				t_ways;

void	copy_one_path(t_list *tmp, t_way *way)
{
	size_t	j;

	j = 0;
	while (tmp)
	{
		way[j].room = ft_strdup(tmp->content);
		way[j].ant	= 0;
		j++;
		tmp = tmp->next;
	}
}

t_ways**	copy_all_paths(t_list *paths)
{
	size_t			num_of_paths;
	t_ways			**ways;
	t_list			*tmp;
	t_list			*head;
	size_t			i;

	i = 0;
	head = paths;
	tmp = (t_list*)paths->content;
	num_of_paths = ft_lstsize(paths);
	ways = (t_ways**)malloc(sizeof(t_ways*) * (num_of_paths + 1)); 
	while (head)
	{
		tmp = (t_list*)head->content;
		ways[i] = (t_ways*)malloc(sizeof(t_ways));
		ways[i]->way = (t_way*)malloc(sizeof(t_way) * head->content_size);
		ways[i]->length = head->content_size;
		ways[i]->ants_q = 0;
		ways[i]->ants_end = 0;
		copy_one_path(tmp, ways[i]->way);
		head = head->next;
		i++;
	}
	ways[i] = NULL;
	return(ways);
}

void	add_ants_to_prev_rooms(size_t i, size_t diff, t_ways **ways,\
													size_t *num_of_ants)
{
	size_t	j;

	j = 0;
	while (j < i && *num_of_ants)
	{
		ways[j]->ants_q += diff;
		j++;
		if (*num_of_ants < diff)
			diff = *num_of_ants;
		*num_of_ants -= diff;
	}
}

void	calc_ants_queue(t_ways** ways, size_t num_of_paths)
{
	size_t	i;
	size_t	j;
	size_t	num_of_ants;
	int		diff;

	i = 0;
	diff = 0;
	j = 0;
	num_of_ants = g_graph->number_of_ants;
	while(num_of_ants > 0 && i + 1 < num_of_paths)
	{
		if (num_of_ants <= 0)
			break ;
		diff = ways[i + 1]->length - ways[i]->length;
		if (diff > (int)num_of_ants)
			diff = num_of_ants;
		ways[i]->ants_q += diff;
		num_of_ants -= diff;
		j = 0;
		add_ants_to_prev_rooms(i, diff, ways, &num_of_ants);
		i++;
	}
}

void	set_to_minus_useless_paths(t_ways **ways)
{
	int	i;

	i = 0;
	while (ways[i])
	{
		if (ways[i]->ants_q == 0)
		{
			ways[i]->ants = 0;
			ways[i]->ants_q = -1;
		}
		else
			ways[i]->ants = ways[i]->ants_q;
		i++;
	}
}

int		check_ants(t_ways **ways)
{
	int	i;

	i = 0;
	while (ways[i]->ants_q != -1)
	{
		if (ways[i]->ants > ways[i]->ants_end)
			return (0);
		i++;
	}
	return (1);
}

void	run_ants(t_list *paths)
{
	size_t			num_of_paths;
	t_ways			**ways;
	size_t			i;
	size_t			j;
	size_t			ant_index;
	size_t			c;

	c = 0;
	ways = copy_all_paths(paths);
	num_of_paths = ft_lstsize(paths);
	calc_ants_queue(ways, num_of_paths);
	set_to_minus_useless_paths(ways);
	i = 0;
	j = 1;
	ant_index = 0;
	// 	for (int i = 0; i < num_of_paths; i++)
	// {
	// 	ft_printf("PATH NUM: %d ANTS QUEUE %d\n", i, ways[i]->ants_q);
	// 	for (int j = 1; j < ways[i]->length; j++) {
	// 			ft_printf("L%d-%s\n", ways[i]->way[j].ant, ways[i]->way[j].room);
	// 	}
	// }
	while (1)
	{
		j = 1;
		while (ways[i]->ants_q != -1)
		{
			if (ways[i]->ants_q == 0 && ways[i]->ants_end != ways[i]->ants)
			{
				while (ways[i]->way[j].ant == 0 && j < ways[i]->length)
					j++;
			}
			while (ways[i]->way[j].ant != 0 && j < ways[i]->length)
				j++;
			while (j > 1)
			{
				if (ways[i]->way[j].ant == 0)
					ways[i]->way[j].ant = ways[i]->way[j - 1].ant;
				if (j == ways[i]->length)
				{
					ways[i]->ants_end++;
					ways[i]->way[j].ant = 0;
					if (ways[i]->ants_q == (int)ways[i]->ants_end)
						ways[i]->ants_q = -1;
				}
				ways[i]->way[j - 1].ant = 0;
				j--;
			}
		j = 1;
		if (ways[i]->ants_q != 0)
		{
			ways[i]->way[j].ant = ant_index + 1;
			ant_index++;
			ways[i]->ants_q--;
		}
		i++;
		}
		if (ways[i]->ants_q == -1)
			i = 0;
		c++;
		for (int i = 0; ways[i]->ants_q != -1; i++)
		{
			for (int j = 1; j < (int)ways[i]->length; j++) {
				if (ways[i]->way[j].ant != 0)
					ft_printf("L%d-%s ", ways[i]->way[j].ant, ways[i]->way[j].room);
			}
			// write(1, "\n", 1);
		}
		if (check_ants(ways) != 1)
			write(1, "\n", 1);
		else
			break ;
	}
	// for (int i = 0; i < 3; i++)
	// {
	// 	ft_printf("PATH NUM: %d ANTS QUEUE %d\n", i, ways[i]->ants_q);
	// 	ft_printf("-------------------------------------------\n");
	// 	for (int j = 1; j < ways[i]->length; j++) {
	// 			ft_printf("[%s] ", ways[i]->way[j].room);
	// 	}
	// 	write(1, "\n", 1);
	// }
	// for (int i = 0; i < num_of_paths; i++)
	// {
	// 	ft_printf("PATH NUM: %d ANTS QUEUE %d\n", i, ways[i]->ants_q);
	// 	for (int j = 1; j < ways[i]->length; j++) {
	// 			ft_printf("L%d-%s\n", ways[i]->way[j].ant, ways[i]->way[j].room);
	// 	}
	// }
}