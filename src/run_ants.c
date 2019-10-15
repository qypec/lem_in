/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:42:51 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/10/15 15:10:27 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_ants(t_ways **ways)
{
	int	i;

	i = 0;
	while (ways[i] != NULL)
	{
		if (ways[i]->ants > ways[i]->ants_end)
			return (0);
		i++;
	}
	return (1);
}

void	push_ants(t_ways **ways, size_t i, size_t j)
{
	if (j == ways[i]->length)
	{
		ways[i]->ants_end++;
		ways[i]->way[j - 1].ant = 0;
		j--;
	}
	while (j > 1)
	{
		if (ways[i]->way[j].ant == 0 && ways[i]->way[j - 1].ant != 0)
		{
			ways[i]->way[j].ant = ways[i]->way[j - 1].ant;
			ways[i]->way[j - 1].ant = 0;
		}
		j--;
	}
}

size_t	move_ants(t_ways **ways, size_t i)
{
	size_t			j;
	static size_t	ant_index;

	j = 1;
	while (ways[i] != NULL && ways[i]->ants_q != -1)
	{
		if (ways[i]->ants_q == 0 && ways[i]->ants_end != ways[i]->ants)
		{
			while (j < ways[i]->length && ways[i]->way[j].ant == 0)
				j++;
		}
		while (j < ways[i]->length && ways[i]->way[j].ant != 0)
			j++;
		push_ants(ways, i, j);
		j = 1;
		if (ways[i]->ants_q > 0)
		{
			ways[i]->way[j].ant = ant_index + 1;
			ant_index++;
			ways[i]->ants_q--;
		}
		i++;
	}
	return (i);
}

void	running(t_ways **ways)
{
	size_t	i;

	i = 0;
	while (1)
	{
		i = move_ants(ways, i);
		print_rooms(ways);
		if (ways[i] == NULL || ways[i]->ants_q == -1)
			i = 0;
		if (check_ants(ways) == 0)
			write(1, "\n", 1);
		else
			break ;
	}
}

void	run_ants(t_list *paths)
{
	t_ways			**ways;
	size_t			num_of_paths;

	num_of_paths = ft_lstsize(paths);
	ways = copy_all_paths(paths, num_of_paths);
	calc_ants_queue(ways, num_of_paths);
	set_to_minus_useless_paths(ways);
	running(ways);
	delete_array_of_paths(ways);
}
