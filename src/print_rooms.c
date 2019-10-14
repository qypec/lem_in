/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:24:44 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/10/14 20:24:56 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_rooms(t_ways **ways)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (ways[i]->ants_q != -1)
	{
		j = 1;
		while (j < ways[i]->length)
		{
			if (ways[i]->way[j].ant != 0)
				ft_printf("L%d-%s ", ways[i]->way[j].ant, ways[i]->way[j].room);
			j++;
		}
		i++;
	}
}
