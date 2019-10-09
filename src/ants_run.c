/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:29:45 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/09 16:55:53 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

		// ft_printf("L%d-%s", room->ant_here, tmp->content);

void				move_paths(t_list **paths)
{
	t_list	*tmp;

	tmp = *paths;
	while (*paths)
	{
		// ft_lstpushback(&queue, ft_lstnew((*paths)->content->content, sizeof(char *)));
		(*paths)->content = ((t_list *)((*paths)->content))->next;
		*paths = (*paths)->next;
	}
	*paths = tmp;
}

int					ants_move(t_list *path, size_t *i)
{
	static int		ant_end;
	t_room			*room;
	t_list			*tmp;
	size_t			j;

	if (path == NULL)
		return (ant_end);
	if (ft_strequ(path->content, END_ROOM))
		ant_end++;
	if ((room = GET_ROOM(g_graph, path->content))->ant_here != 0)
	{
		tmp = path;
		tmp = tmp->next;
		j = room->ant_here;
		ants_move(tmp, &j);
		room->ant_here = 0;
	}
	else
	{
		room->ant_here = *i;
		ft_printf("L%d-%s", room->ant_here, path->content);
		*i += 1;
	}
	return (ant_end);
}

void				ants_run(t_list *paths)
{
	t_list			*tmp;
	size_t			i;
	int				ant_end;

	i = 1;
	move_paths(&paths);
	while (paths->content != NULL)
	{
		tmp = paths;
		while (tmp != NULL)
		{
			ant_end = ants_move(tmp->content, &i);
			if (i > g_graph->number_of_ants)
			{
				move_paths(&paths);
				i = ant_end + 1;
				break ;
			}
			// ft_printf("\ni = %d\n", i);
			ft_putchar(' ');
			tmp = tmp->next;
		}
	}
}
