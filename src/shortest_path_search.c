/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:47:12 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/27 05:11:25 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list				*bfs(t_list	**head, char *room_name)
{
	t_list			*link;

	ft_lstpushback(head, ft_lstnew(ft_strdup(room_name), sizeof(char *)));
	// printf("%s\n", (char *)(*head)->content);
	if (ft_strequ(g_graph->end, room_name))
		return (*head);
	link = ((t_room *)ft_mapvalue(g_graph->map, room_name))->link;
	while (link != NULL)
	{
		if (bfs(&((*head)->next), ((t_links *)(link->content))->name) != NULL)
			return (*head);
		link = link->next;
	}
	ft_lstdelone(head, &spath_del);
	return (NULL);
}

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
	bfs(&spath, g_graph->start);
	if (spath == NULL)
		error_processing(&spath);
	
	ft_lstdel(&spath, &spath_del);
	// ft_lstprint(spath, &print);
}