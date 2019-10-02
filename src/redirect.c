/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:23:34 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/02 17:31:47 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void				redirect_path_from_end_to_start(t_list *path)
{
	t_room			*prev_room;
	t_room			*current_room;

	while (path->next != NULL)
	{
		prev_room = GET_ROOM(path->content);
		current_room = GET_ROOM(path->next->content);
		ft_lstadd(&(current_room->link), ft_lstnew(linksinit(PREV_ROOM_NAME, 0), sizeof(t_links *)));
		delete_link(&(prev_room->link), CURRENT_ROOM_NAME);
		path = path->next;
	}
}
