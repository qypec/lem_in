/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:47:12 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/29 10:49:06 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// debugging
void				printdbl(void *ptr)
{
	ft_printf("current = '%s'\n  prev = '%s'", ((t_prev *)(ptr))->current, ((t_prev *)(ptr))->prev);
}

void				print(void *str)
{
	ft_putstr(str);
}

void				del_prevroom(void *content, size_t content_size)
{
	ft_strdel(&((t_prev *)(content))->current);
	ft_strdel(&((t_prev *)(content))->prev);
	free(content);
	content = NULL;
	content_size = 0;
}

void				del(void *str, size_t size)
{
	ft_strdel((char **)&str);
	size = 0;
}
//

t_list				*get_path(t_list **allpaths)
{
	t_list			*result;
	char			*prev_room_name;

	if (*allpaths == NULL)
		return (NULL);
	result = NULL;
	prev_room_name = ft_strdup(((t_prev *)((*allpaths)->content))->current);
	while (*allpaths != NULL)
	{
		if (ft_strequ(prev_room_name, ((t_prev *)((*allpaths)->content))->current))
		{
			ft_lstadd(&result, ft_lstnew(ft_strdup(((t_prev *)((*allpaths)->content))->current), sizeof(char *)));
			ft_strdel(&prev_room_name);
			prev_room_name = ft_strdup(((t_prev *)((*allpaths)->content))->prev);
		}
		ft_lstdelone(allpaths, del_prevroom);
	}
	ft_lstadd(&result, ft_lstnew(ft_strdup(START_ROOM), sizeof(char *)));
	ft_lstdel(allpaths, del_prevroom);
	ft_strdel(&prev_room_name);
	return (result);
}

t_list				*bfs(void)
{
	t_list			*queue;
	t_list			*allpaths;
	t_list			*link;
	t_room			*room;
	char			*tmp_prev;

	allpaths = NULL;
	queue = NULL;
	tmp_prev = NULL;
	ft_lstpushback(&queue, ft_lstnew(ft_strdup(START_ROOM), sizeof(char *)));
	while (queue != NULL)
	{
		link = (t_list *)((t_room *)(ft_mapvalue(g_graph->map, (char *)(queue->content))))->link;
		ft_strdel(&tmp_prev);
		tmp_prev = ft_strdup((char *)(queue->content));
		ft_lstdelone(&queue, &del);
		while (link != NULL)
		{
			room = ((t_room *)(ft_mapvalue(g_graph->map, LINKS_NAME)));
			if (!(room->is_visited))
			{
				room->is_visited = 1;
				ft_lstpushback(&queue, ft_lstnew(ft_strdup(LINKS_NAME), sizeof(char *)));
				ft_lstadd(&allpaths, ft_lstnew(prev_room_init(LINKS_NAME, tmp_prev), sizeof(t_prev *)));
				if (ft_strequ(LINKS_NAME, END_ROOM))
				{
					ft_lstdel(&queue, del);
					break ;
				}
			}
			link = link->next;
		}
	}
	ft_lstdel(&queue, del);
	ft_strdel(&tmp_prev);
	return (get_path(&allpaths));
}

void				algorithm(void)
{
	t_list		*spath;

	spath = bfs();
	if (spath == NULL)
		error_processing(&spath);
	
	ft_printf("spath:\n");
	ft_putlst(spath, &print);
	ft_lstdel(&spath, &spath_del);
}
