/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:18:37 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/22 22:24:36 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_links				*linksinit(const char *name, int wt)
{
	t_links			*link;

	if ((link = (t_links *)malloc(sizeof(t_links))) == NULL)
		return (NULL);
	link->name = ft_strdup(name);
	link->wt = wt;
	return (link);
}

t_room				*roominit(void)
{
	t_room			*room;

	if ((room = (t_room *)malloc(sizeof(t_room))) == NULL)
		return (NULL);
	room->ant_here = 0;
	room->link = NULL;
	return (room);
}

void				linksdel(void *content, size_t content_size)
{
	content_size = 0;
	ft_strdel(&(((t_links *)content)->name));
	((t_links *)content)->wt = 0;
	free(content);
	content = NULL;
}

void				roomdel(void **room)
{
	ft_lstdel(&(((t_room *)(*room))->link), &linksdel);
	((t_room *)(*room))->ant_here = 0;
	free(*room);
	*room = NULL;
}
