/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 11:00:26 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/10 21:21:17 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define CURRENT_LINK ((t_prev *)((*pathstack)->content))->current
#define PREV_LINK ((t_prev *)((*pathstack)->content))->prev

static void			set_zero_elem(t_list *elem)
{
	((t_room *)(((t_htab *)(elem->content))->value))->is_visited = 0;
}

static void			set_to_zero_isvisited_flag(void)
{
	size_t			i;
	t_list			*maplst;

	i = 0;
	while (i < g_graph->map->size)
	{
		maplst = g_graph->map->array[i];
		if (maplst != NULL)
			ft_lstiter(maplst, set_zero_elem);
		i++;
	}
}

static t_list		*get_path(t_list **pathstack)
{
	t_list			*result;
	char			*prev_room_name;

	g_lstsize = 0;
	if (*pathstack == NULL)
		return (NULL);
	result = NULL;
	if (!ft_strequ(CURRENT_LINK, END_ROOM))
		return (ft_lstdel(pathstack, del_prevroom));
	prev_room_name = ft_strdup(CURRENT_LINK);
	while (*pathstack != NULL)
	{
		if (ft_strequ(prev_room_name, CURRENT_LINK))
		{
			ft_lstadd(&result, \
				ft_lstnew(ft_strdup(CURRENT_LINK), sizeof(char *)));
			g_lstsize++;
			ft_strdel(&prev_room_name);
			prev_room_name = ft_strdup(PREV_LINK);
		}
		ft_lstdelone(pathstack, del_prevroom);
	}
	ft_lstadd(&result, ft_lstnew(ft_strdup(START_ROOM), sizeof(char *)));
	g_lstsize++;
	ft_lstdel(pathstack, del_prevroom);
	ft_strdel(&prev_room_name);
	/*
	** add path length to content size of list
	*/
	result->content_size = g_lstsize;
	return (result);
}

static void			add_links_to_queue(t_list **queue, t_list **pathstack, \
						t_list *link, char *parent_name)
{
	t_room			*room;

	while (link != NULL)
	{
		room = ((t_room *)(ft_mapvalue(g_graph->map, LINKS_NAME(link))));
		if (!(room->is_visited))
		{
			room->is_visited = 1;
			ft_lstpushback(queue, \
				ft_lstnew(ft_strdup(LINKS_NAME(link)), sizeof(char *)));
			ft_lstadd(pathstack, \
				ft_lstnew(prev_room_init(LINKS_NAME(link), parent_name), \
					sizeof(t_prev *)));
			if (ft_strequ(LINKS_NAME(link), END_ROOM))
			{
				ft_lstdel(queue, del_str_from_list);
				break ;
			}
		}
		link = link->next;
	}
}

t_list				*shortest_path_search(void)
{
	t_list			*queue;
	t_list			*pathstack;
	t_room			*room;
	char			*parent_name;
	t_list			*result;

	pathstack = NULL;
	queue = NULL;
	parent_name = NULL;
	ft_lstpushback(&queue, ft_lstnew(ft_strdup(START_ROOM), sizeof(char *)));
	while (queue != NULL)
	{
		if ((room = (t_room *)GET_ROOM(g_graph, queue->content)) == NULL)
			return (NULL);
		parent_name = ft_strdup((char *)(queue->content));
		ft_lstdelone(&queue, del_str_from_list);
		add_links_to_queue(&queue, &pathstack, room->link, parent_name);
		ft_strdel(&parent_name);
	}
	result = get_path(&pathstack);
	set_to_zero_isvisited_flag();
	return (result);
}
