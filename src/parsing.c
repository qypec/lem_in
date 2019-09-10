/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:30:21 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/10 14:59:43 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					is_comment_line(char *line)
{

}

int					is_number_of_ant_line(char *line)
{

}

int					is_room_name_line(char *line)
{

}

int					is_room_link_line(char *line)
{

}

int					what_is_this_line(char **line)
{
	static int		start_room_counter;
	static int		end_room_counter;
	static int		number_of_ants_counter;
	int				qualifier;

	if ((qualifier = is_comment_line(line)) != 0)
		return (qualifier);
	if (is_room_name_line(line))
		return (DEFAULT_ROOM_LINE);
	if (is_number_of_ant_line(line))
		return (NUMBER_OF_ANTS_LINE);
	if (is_room_link_line(line))
		return (ROOM_LINK_LINE);
}

void				error_processing(char **line)
{
	ft_strdel(line);
	ft_printf("ERROR\n");
	exit(1);
}

void				parsing(void)
{
	char			*line;
	int				qualifier;
	t_list			*end_room;
	t_list			*start_room;

	while (get_next_line(0, line) > 0)
	{
		qualifier = what_is_this_line(&line);
		if (qualifier == COMMENT_LINE)
			continue ;
		else if (qualifier == START_ROOM_LINE && get_next_line(0, line) > 0)
			start_room = ft_lstnew((void *)newroom(line), &roomdel);
		else if (qualifier == END_ROOM_LINE && get_next_line(0, line) > 0)
			end_room = ft_lstnew((void *)newroom(line), &roomdel);
		else if (qualifier == DEFAULT_ROOM_LINE)
			ft_lstpushback(&g_room, ft_lstnew((void *)newroom(line), &roomdel));
		else if (qualifier == NUMBER_OF_ANTS_LINE)
			g_number_of_ants = ft_atoi((const char *)line);
		else if (qualifier == ROOM_LINK_LINE)
			add_room_link(line);
	}
	ft_strdel(&line);
	ft_lstpushback(&g_room, end_room);
	ft_lstadd(&g_room, start_room);
}













