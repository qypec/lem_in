/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array_of_paths.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:22:45 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/10/14 20:42:09 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void	copy_one_path(t_list *tmp, t_way *way)
{
	size_t	j;

	j = 0;
	while (tmp)
	{
		way[j].room = ft_strdup(tmp->content);
		way[j].ant = 0;
		j++;
		tmp = tmp->next;
	}
}

t_ways	**copy_all_paths(t_list *paths)
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
	return (ways);
}

void	delete_array_of_paths(t_ways **ways)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (ways[i])
	{
		j = 0;
		while (j < ways[i]->length)
		{
			free(ways[i]->way[j].room);
			j++;
		}
		free(ways[i]->way);
		free(ways[i]);
		i++;
	}
	free(ways);
}
