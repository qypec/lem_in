/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:29:45 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/10 18:09:36 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

		// ft_printf("L%d-%s", room->ant_here, tmp->content);

int					paths_not_null(t_list *paths)
{
	while (paths != NULL)
	{
		if (paths->content != NULL)
			return (1);
		paths = paths->next;
	}
	return (0);
}

t_list				*move_path(t_list **paths, t_list *path)
{
	t_list			*tmp;
	t_list			*moved;

	// if (path == NULL)
	// 	return (NULL);
	if ((GET_ROOM(g_graph, path->content))->ant_here != 0)
		return (NULL);
	moved = NULL;
	tmp = *paths;
	while (*paths != NULL)
	{
		if ((*paths)->content == path)
		{
			(*paths)->content = ((t_list *)((*paths)->content))->next;
			moved = *paths;
			break ;
		}
		*paths = (*paths)->next;
	}
	*paths = tmp;
	return (moved);
}

void				move_all_paths(t_list **paths)
{
	t_list	*tmp;

	tmp = *paths;
	while (*paths)
	{
		(*paths)->content = ((t_list *)((*paths)->content))->next;
		*paths = (*paths)->next;
	}
	*paths = tmp;
}

void				run_ant(t_list *path, size_t ant_number)
{
	t_room			*room;

	if (path == NULL)
		return ;
	if ((room = GET_ROOM(g_graph, path->content))->ant_here)
		run_ant(path->next, room->ant_here);
	room->ant_here = 0;
	if (ant_number != 0)
	{
		room->ant_here = ant_number;
		ft_printf("L%d-%s ", room->ant_here, path->content);
	}
}

// void				disconnect_path(t_list **paths)
// {
// 	while (*paths != NULL)
// 	{
// 		if ((*paths)->content == NULL)
// 		{
// 			(*paths) = (*paths)->next;
// 			break ;
// 		}
// 		*paths = (*paths)->next;
// 	}
// }

void				ants_run(t_list *paths)
{
	size_t			ant_number;
	t_list			*tmp_paths;
	t_list			*tmp;
	t_list			*tmp2;

	tmp_paths = paths;
	move_all_paths(&paths);
	ant_number = 1;
	while (1)
	{
		tmp = paths;
		while (tmp != NULL)
		{
			run_ant(tmp->content, ant_number);
			if (ant_number + 1 > g_graph->number_of_ants || ant_number == 0)
			{
				ant_number = 0;
				if (tmp->content == NULL)
				{
					tmp = tmp->next;
					continue ;
					// disconnect_path(&paths);
				}
				if ((tmp2 = move_path(&paths, tmp->content)) == NULL)
					break ;
				tmp = tmp2;
			}
			else
				ant_number++;
			tmp = tmp->next;
		}
		if ((paths_not_null(paths)) == 0)
			break ;
		ft_putchar('\n');
	}
}
