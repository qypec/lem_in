/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:18:37 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/28 21:20:02 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_prev				*prev_room_init(char *current, char *prev_str)
{
	t_prev			*prev;

	if ((prev = (t_prev *)malloc(sizeof(t_prev))) == NULL)
		return (NULL);
	prev->current = ft_strdup(current);
	prev->prev = ft_strdup(prev_str);
	return (prev);
}

void				prev_room_del(t_prev **prev)
{
	ft_strdel(&((*prev)->current));
	ft_strdel(&((*prev)->prev));
	free(*prev);
	*prev = NULL;
}

t_graph				*graphinit(void)
{
	t_graph			*graph;

	if ((graph = (t_graph *)malloc(sizeof(t_graph))) == NULL)
		return (NULL);
	if ((graph->map = ft_mapinit(10, &roomdel)) == NULL)
	{
		free(graph);
		graph = NULL;
		return (NULL);
	}
	graph->number_of_ants = 0;
	graph->start = NULL;
	graph->end = NULL;
	return (graph);
}

void				graphdel(t_graph **graph)
{
	ft_mapdel(&((*graph)->map));
	(*graph)->number_of_ants = 0;
	ft_strdel(&((*graph)->start));
	ft_strdel(&((*graph)->end));
	free(*graph);
	*graph = NULL;
}

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
	room->is_visited = 0;
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
	((t_room *)(*room))->is_visited = 0;
	free(*room);
	*room = NULL;
}
