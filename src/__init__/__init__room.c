/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:28:04 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/14 11:28:33 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room				*roominit(void)
{
	t_room			*room;

	if ((room = (t_room *)malloc(sizeof(t_room))) == NULL)
		return (NULL);
	room->is_visited = 0;
	room->ant_here = 0;
	room->link = NULL;
	return (room);
}

void				roomdel(void **room)
{
	ft_lstdel(&(((t_room *)(*room))->link), &linksdel);
	((t_room *)(*room))->ant_here = 0;
	((t_room *)(*room))->is_visited = 0;
	free(*room);
	*room = NULL;
}
