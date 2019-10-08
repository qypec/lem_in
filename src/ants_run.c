/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:29:45 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/08 19:10:52 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				add_next_rooms_to_queue(t_list **queue, t_list **paths)
{
	t_list	*tmp;

	tmp = *paths;
	while (*paths)
	{
		ft_lstpushback(&queue, ft_lstnew((*paths)->content->content, sizeof(char *)));
		(*paths)->content = (*paths)->content->next;
		*paths = (*paths)->next;
	}
	*paths = tmp;
}

void				ants_run(t_list *paths)
{
	size_t			i;
	t_list			*queue;
	t_list			*tmp;
	t_room			*room;
	t_list			*tmp_paths;

	queue = NULL;
	tmp_paths = paths;
	add_next_rooms_to_queue(&queue, &paths);
	i = 1;
	while (queue != NULL)
	{
		tmp = queue;
		if ((room = GET_ROOM(g_graph, queue->content))->ant_here == 0)
			room->ant_here = (i++);
		ft_printf("L%d-%s", room->ant_here, queue->content);
		if (queue->next != NULL)
		{
			ft_putchar(" ");
			queue = queue->next;
		}
		else
		{
			ft_putchar("\n");
			add_next_rooms_to_queue(&queue, &paths);
		}
		// if (i > g_graph->number_of_ants)


	}
}
