/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 02:56:33 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/25 04:26:41 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				add_room_link(char *line)
{
	const char		*ptr;
	char			*room_name;
	const void		*value;

	ptr = ft_strchr(line, '-');
	room_name = ft_strsub(line, 0, ptr - line);
	if ((value = ft_mapvalue(g_graph, room_name)) == NULL)
		error_processing(&line);
	ft_strdel(&room_name);
	ft_lstadd(&(((t_room *)value)->link), \
		ft_lstnew(linksinit(++ptr, 0), sizeof(t_links *)));
}

void				add_start_room(char *line)
{
	if (get_next_line(0, &line) < 0 || !is_room_name_line(line))
		error_processing(&line);
	g_start = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
	ft_mapinsert(g_graph, g_start, roominit());
}

void				add_end_room(char *line)
{
	if (get_next_line(0, &line) < 0 || !is_room_name_line(line))
		error_processing(&line);
	g_end = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
	ft_mapinsert(g_graph, g_end, roominit());
}

void				add_room(char *line)
{
	char			*room_name;

	room_name = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
	ft_mapinsert(g_graph, room_name, roominit());
	ft_strdel(&room_name);
}

void				add_number_of_ants(char *line)
{
	g_number_of_ants = ft_atoi(line);
}
