/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 02:56:33 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/27 10:22:17 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				add_room_link(char **line)
{
	const char		*link_name;
	char			*room_name;
	const void		*value;

	link_name = ft_strchr(*line, '-');
	room_name = ft_strsub(*line, 0, link_name - *line);
	if (!ft_ismapitem(g_graph->map, ++link_name) || \
							ft_strequ(room_name, link_name))
	{
		ft_strdel(&room_name);
		error_processing_line(line);
	}
	if ((value = ft_mapvalue(g_graph->map, room_name)) == NULL)
		error_processing_line(line);
	ft_strdel(&room_name);
	ft_lstadd(&(((t_room *)value)->link), \
		ft_lstnew(linksinit(link_name, 0), sizeof(t_links *)));
}

void				add_start_room(char **line)
{
	if (get_next_line(g_fd, line) < 0 || !is_room_name_line(*line))
		error_processing_line(line);
	g_graph->start = ft_strsub(*line, 0, ft_strchr(*line, ' ') - *line);
	if (ft_ismapitem(g_graph->map, g_graph->start))
		error_processing_line(line);
	ft_mapinsert(g_graph->map, g_graph->start, roominit());
}

void				add_end_room(char **line)
{
	if (get_next_line(g_fd, line) < 0 || !is_room_name_line(*line))
		error_processing_line(line);
	g_graph->end = ft_strsub(*line, 0, ft_strchr(*line, ' ') - *line);
	if (ft_ismapitem(g_graph->map, g_graph->end))
		error_processing_line(line);
	ft_mapinsert(g_graph->map, g_graph->end, roominit());
}

void				add_room(char **line)
{
	char			*room_name;

	room_name = ft_strsub(*line, 0, ft_strchr(*line, ' ') - *line);
	if (ft_ismapitem(g_graph->map, room_name))
		error_processing_line(line);
	ft_mapinsert(g_graph->map, room_name, roominit());
	ft_strdel(&room_name);
}

void				add_number_of_ants(char **line)
{
	g_graph->number_of_ants = ft_atoi(*line);
}
