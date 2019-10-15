/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ants_queue.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:23:57 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/10/15 15:09:39 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	fill_queue(t_ways **ways, size_t border_number, size_t diff)
{
	static size_t	num_of_ants = 0;
	size_t			ants_counter;
	size_t			i;

	if (diff == 0)
		return (num_of_ants);
	ants_counter = 0;
	while (ants_counter < diff)
	{
		i = 0;
		while (i < border_number)
		{
			if (num_of_ants == g_graph->number_of_ants)
				return (num_of_ants);
			if (i == border_number - 1)
				ants_counter++;
			ways[i]->ants_q++;
			i++;
			num_of_ants++;
		}
	}
	return (num_of_ants);
}

void	calc_ants_queue(t_ways **ways, size_t num_of_paths)
{
	size_t	i;
	size_t	num_of_ants;
	size_t	diff;

	i = 0;
	num_of_ants = 0;
	while (num_of_ants < g_graph->number_of_ants)
	{
		if (ways[i + 1] == NULL)
			i = 0;
		if (num_of_paths == 1)
		{
			ways[i]->ants_q = g_graph->number_of_ants;
			return ;
		}
		diff = ways[i + 1]->length - ways[i]->length;
		num_of_ants = fill_queue(ways, i + 1, diff);
		i++;
	}
}
