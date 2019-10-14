/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_of_paths.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:36:11 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/14 21:06:27 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "jumper__sps.h"

#define PREV_ROOM_NAME path->content
#define CURRENT_ROOM_NAME path->next->content

void				delete_link(t_list **link, const char *del_link_name)
{
	while (*link != NULL)
	{
		if (ft_strequ(LINKS_NAME(*link), del_link_name))
		{
			ft_lstdelone(link, linksdel);
			break ;
		}
		link = &(*link)->next;
	}
}

void				redirect_path(t_list *path)
{
	t_room			*prev_room;
	t_room			*current_room;

	while (path->next != NULL)
	{
		prev_room = GET_ROOM(g_graph, path->content);
		current_room = GET_ROOM(g_graph, path->next->content);
		ft_lstadd(&(current_room->link), \
			ft_lstnew(linksinit(PREV_ROOM_NAME, 0), sizeof(t_links *)));
		delete_link(&(prev_room->link), CURRENT_ROOM_NAME);
		path = path->next;
	}
}

void				add_path_in_sorting_order(t_list **allpaths, \
						t_list *new_path)
{
	size_t			newpath_size;
	t_list			*tmp;

	newpath_size = jumper__sps(GET);
	while (*allpaths != NULL && newpath_size > (*allpaths)->content_size)
		allpaths = &(*allpaths)->next;
	tmp = *allpaths;
	*allpaths = ft_lstnew(new_path, newpath_size);
	(*allpaths)->next = tmp;
}

t_list				*create_list_of_paths(void)
{
	t_list			*allpaths;
	t_list			*path;
	t_list			*first_path;

	allpaths = NULL;
	if ((first_path = shortest_path_search()) == NULL)
		error_processing(&first_path);
	redirect_path(first_path);
	add_path_in_sorting_order(&allpaths, first_path);
	while ((path = shortest_path_search()) != NULL)
	{
		redirect_path(path);
		add_path_in_sorting_order(&allpaths, path);
	}
	return (allpaths);
}
