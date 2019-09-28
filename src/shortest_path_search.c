/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:47:12 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/28 18:29:19 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// t_list				*dfs(t_list	**head, char *room_name)
// {
// 	t_list			*link;
// 	t_room			*room;

// 	ft_lstpushback(head, ft_lstnew(ft_strdup(room_name), sizeof(char *)));
// 	// printf("%s\n", (char *)(*head)->content);
// 	if (ft_strequ(g_graph->end, room_name))
// 		return (*head);
// 	room = (t_room *)ft_mapvalue(g_graph->map, room_name);
// 	room->is_visited = 1;
// 	link = room->link;
// 	while (link != NULL)
// 	{
// 		if (!(((t_room *)(ft_mapvalue(g_graph->map, ((t_links *)(link->content))->name)))->is_visited))
// 		{
// 			if (dfs(&((*head)->next), ((t_links *)(link->content))->name) != NULL)
// 				return (*head);
// 		}
// 		link = link->next;
// 	}
// 	room->is_visited = 0;
// 	ft_lstdelone(head, &spath_del);
// 	return (NULL);
// }

void				del(void *str, size_t size)
{
	ft_strdel((char **)&str);
	size = 0;
}

// t_list				*get_path(t_list **prev_room)
// {
// 	t_list			*result;
// }

// t_list				*bfs(void)
// {
// 	t_list			*queue;
// 	t_list			*prev_room;
// 	t_list			*link;
// 	t_room			*room;
// 	char			*tmp_prev;

// 	prev_room = NULL;
// 	ft_lstpushback(&queue, ft_lstnew(ft_strdup(g_graph->start), sizeof(char *)));
// 	while (queue != NULL)
// 	{
// 		link = (t_list *)((t_room *)(ft_mapvalue(g_graph->map, (char *)(queue->content))))->link;
// 		tmp_prev = ft_strdup((char *)(queue->content));
// 		ft_lstdelthis(&queue, 0, &del);
// 		while (link != NULL)
// 		{
// 			room = ((t_room *)(ft_mapvalue(g_graph->map, ((t_links *)(link->content))->name)));
// 			if (!(room->is_visited))
// 			{
// 				ft_lstpushback(&queue, ft_lstnew(ft_strdup(((t_links *)(link->content))->name), sizeof(char *)));
// 				room->is_visited = 1;
// 				ft_lstpushback(&prev_room, ft_lstnew(prev_room_init(((t_links *)(link->content))->name, tmp_prev), sizeof(t_prev *)));
// 				if (ft_strequ(((t_links *)(link->content))->name, g_graph->end))
// 				{
// 					ft_lstdel(&queue, &del);
// 					break ;
// 				}
// 			}
// 			link = link->next;
// 		}
// 	}
// 	return (get_path(&prev_room));
// }

// debugging
void				print(void *str)
{
	ft_putstr(str);
}
//

void				algorithm(void)
{
	t_list			*spath;

	spath = NULL;
	// bfs();
	if (spath == NULL)
		error_processing(&spath);
	
	ft_putlst(spath, &print);
	ft_lstdel(&spath, &spath_del);
}
