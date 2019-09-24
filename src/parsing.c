/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:30:21 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/25 00:38:28 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			add_room_link(char *line)
{
	const char		*ptr;
	char			*room_name;
	const void		*value;

	ptr = ft_strchr(line, '-');
	room_name = ft_strsub(line, 0, ptr - line);
	value = ft_mapvalue(g_graph, room_name);
	ft_strdel(&room_name);
	ft_lstadd(&(((t_room *)value)->link), \
		ft_lstnew(linksinit(++ptr, 0), sizeof(t_links *)));
}

static void			add_room_line(char *line, size_t qualifier)
{
	char			*room_name;

	if (qualifier == START_ROOM_LINE)
	{
		if (get_next_line(g_fd, &line) < 0 || !is_room_name_line(line))
			error_processing(&line);
		g_start = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
		ft_mapinsert(g_graph, g_start, roominit());
	}
	else if (qualifier == END_ROOM_LINE)
	{
		if (get_next_line(g_fd, &line) < 0 || !is_room_name_line(line))
			error_processing(&line);
		g_end = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
		ft_mapinsert(g_graph, g_end, roominit());
	}
	else if (qualifier == DEFAULT_ROOM_LINE)
	{
		room_name = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
		ft_mapinsert(g_graph, room_name, roominit());
		ft_strdel(&room_name);
	}
}

void				parsing(void)
{
	char			*line;
	size_t			qualifier;

	line = NULL;
	while (get_next_line(g_fd, &line) > 0)
	{
		if ((qualifier = what_is_this_line(line)) == COMMENT_LINE)
			continue ;
		else if (qualifier == START_ROOM_LINE || qualifier == END_ROOM_LINE \
			|| qualifier == DEFAULT_ROOM_LINE)
			add_room_line(line, qualifier);
		else if (qualifier == NUMBER_OF_ANTS_LINE)
			g_number_of_ants = ft_atoi(line);
		else if (qualifier == ROOM_LINK_LINE)
			add_room_link(line);
		else
			error_processing(&line);
	}
	if (g_number_of_ants == 0 || g_start == NULL || g_end == NULL)
		error_processing(&line);
}
