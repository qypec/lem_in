/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:42:51 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/10/12 18:05:40 by yquaro           ###   ########.fr       */
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
	size_t		ants_q;
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
	ways = (t_ways**)malloc(sizeof(t_ways*) * num_of_paths + 1); 
	while (head)
	{
		tmp = (t_list*)head->content;
		ways[i] = (t_ways*)malloc(sizeof(t_ways));
		ways[i]->way = (t_way*)malloc(sizeof(t_way) * tmp->content_size);
		ways[i]->length = tmp->content_size;
		ways[i]->ants_q = 0;
		copy_one_path(tmp, ways[i]->way);
		head = head->next;
		i++;
	}
	ways[i] = NULL;
	return(ways);
}

void	calc_ants_queue(t_ways** ways, size_t num_of_paths)
{
	size_t	i;
	size_t	j;
	int		diff;

	i = 0;
	diff = 0;
	j = 0;
	while(g_graph->number_of_ants > 0 && i + 1 < num_of_paths)
	{
		if (g_graph->number_of_ants <= 0)
			break ;
		if (i >= num_of_paths)
			i = 0;
		diff = ways[i + 1]->length - ways[i]->length;
		j = 0;
		while (j <= i)
		{
			if (g_graph->number_of_ants <= 0)
				break ;
			ways[j]->ants_q += diff;
			j++;
			g_graph->number_of_ants -= diff;
		}
		i++;
	}
}

void	run_ants(t_list *paths)
{
	size_t			num_of_paths;
	t_ways			**ways;

	ways = copy_all_paths(paths);
	num_of_paths = ft_lstsize(paths);
	calc_ants_queue(ways, num_of_paths);
	for (int i = 0; i < num_of_paths; i++)
	{
		ft_printf("PATH LEN: %d ANTS QUEUE %d\n", ways[i]->length, ways[i]->ants_q);
		// for (int j = 0; j < ways[i]->length; j++) {
		// 	ft_printf("Room Name: %s Ant here: %d\n", ways[i]->way[j].room, ways[i]->way[j].ant);
		// }
	}
}