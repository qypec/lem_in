/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:18:37 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/10 14:36:28 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				roomdel(t_list *dellist)
{
	ft_strdel(&(dellist->room->name));
	dellist->room->name = NULL;
	ft_lstdel(dellist->room->link);
	dellist->room->link = NULL;
	free(dellist->room);
	dellist->room = NULL;
}

t_room				*newroom(char *line)
{
	t_room			*room;

	if ((room = (t_room *)malloc(sizeof(t_room))) == NULL)
		exit(-1);
	room->name = get_room_name(line);
	room->link = NULL;
	return (room);
}
