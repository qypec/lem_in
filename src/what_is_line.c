/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_is_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:17:44 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/25 04:28:42 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			*what_is_comment_line(char *line)
{
	static int		start_line_counter;
	static int		end_line_counter;

	if (ft_strnequ(line, "##start", 7) && line[7] == '\0')
	{
		if (++start_line_counter > 1)
			error_processing(&line);
		return (START_ROOM_LINE);
	}
	else if (ft_strnequ(line, "##end", 5) && line[5] == '\0')
	{
		if (++end_line_counter > 1)
			error_processing(&line);
		return (END_ROOM_LINE);
	}
	else
		return (COMMENT_LINE);
}

static int			is_number_of_ant_line(char *line)
{
	static int		number_of_ants_counter;
	size_t			i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!ft_isdigit(line[i++]))
			return (0);
	}
	if (++number_of_ants_counter > 1)
		error_processing(&line);
	return (1);
}

int					is_room_name_line(const char *line)
{
	char			*tmp;
	int				ret;

	tmp = (char *)line;
	if (!(ret = is_room_name(tmp)))
		return (0);
	if (*(tmp + ret) != ' ')
		return (0);
	tmp += (ret + 1);
	if (!ft_isdigit(*tmp))
		return (0);
	if ((tmp = (char *)ft_strchr(tmp, ' ')) == NULL)
		return (0);
	if (ft_strchr(++tmp, ' ') != NULL)
		return (0);
	return (1);
}

static int			is_room_link_line(const char *line)
{
	char			*tmp;
	int				ret;

	tmp = (char *)line;
	if (!(ret = is_room_name(tmp)))
		return (0);
	if (*(tmp + ret) != '-')
		return (0);
	tmp += (ret + 1);
	if (!(ret = is_room_name(tmp)))
		return (0);
	if (*(tmp + ret) != '\0')
		return (0);
	return (1);
}

void				*what_is_this_line(char *line)
{
	if (*line == '#')
		return (what_is_comment_line(line));
	else if (is_number_of_ant_line(line))
		return (NUMBER_OF_ANTS_LINE);
	else if (is_room_name_line((const char *)line))
		return (DEFAULT_ROOM_LINE);
	else if (is_room_link_line((const char *)line))
		return (ROOM_LINK_LINE);
	else
		error_processing(&line);
	return (NULL);
}