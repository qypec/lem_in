/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimum_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:58:59 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/14 21:13:20 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				delete_links_between_same_rooms(t_graph *graph, \
						t_list **same_room)
{
	t_room			*prev_room;
	t_room			*next_room;
	t_list			*tmp;
	const char		*del_room_name;

	if ((tmp = (*same_room)) == NULL)
		return ;
	while (tmp->next != NULL)
	{
		prev_room = GET_ROOM(graph, tmp->content);
		del_room_name = tmp->content;
		tmp = tmp->next;
		next_room = GET_ROOM(graph, tmp->content);
		delete_link(&(prev_room->link), tmp->content);
		delete_link(&(next_room->link), del_room_name);
	}
	ft_lstdel(same_room, delfunc_lst__str);
}

t_list				*find_same_rooms(t_list *shortest_path, t_list *path)
{
	t_list			*tmp;
	t_list			*same_room;

	tmp = path;
	same_room = NULL;
	shortest_path = shortest_path->next;
	while (shortest_path->next != NULL)
	{
		path = tmp;
		while (path != NULL)
		{
			if (ft_strequ(shortest_path->content, path->content))
			{
				ft_lstadd(&same_room, \
					ft_lstnew(ft_strdup(path->content), sizeof(char *)));
				break ;
			}
			path = path->next;
		}
		shortest_path = shortest_path->next;
	}
	return (same_room);
}

void				find_optimum_ways(t_list **paths, t_graph *graph)
{
	t_list			*tmp;
	t_list			*shortest_path;
	t_list			*same_room;

	tmp = *paths;
	shortest_path = tmp->content;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		same_room = find_same_rooms(shortest_path, tmp->content);
		delete_links_between_same_rooms(graph, &same_room);
		tmp = tmp->next;
	}
	ft_lstdel(paths, delfunc_lst__list);
	graphdel(&g_graph);
	g_graph = graph;
	*paths = create_list_of_paths();
}
