/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:24:44 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/10/15 17:58:25 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_rooms(t_ways **ways)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (ways[i] != NULL && ways[i]->ants_q != -1)
	{
		j = 1;
		while (j < ways[i]->length)
		{
			if (ways[i]->way[j].ant != 0)
			{
				write(1, "L", 1);
				ft_putnbr(ways[i]->way[j].ant);
				write(1, "-", 1);
				ft_putstr(ways[i]->way[j].room);
				if (j + 1 < ways[i]->length && ways[i]->way[j + 1].ant != 0)
					write(1, " ", 1);
			}
			j++;
		}
		if (ways[i + 1] != NULL && ways[i + 1]->ants_q != -1 && ways[i]->ants_end < ways[i]->ants)
			write(1, " ", 1);
		i++;
	}
}
