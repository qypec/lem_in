/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_is_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:17:44 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/22 22:37:09 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			is_comment_line(char *line)
{
	static int		start_line_counter;
	static int		end_line_counter;

	if (*line != '#')
		return (0);
	else if (ft_strnequ(line, "##start", 7))
	{
		if (++start_line_counter > 1)
			error_processing(&line);
		return (START_ROOM_LINE);
	}
	else if (ft_strnequ(line, "##end", 5))
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

int					is_room_name_line(char *line)
{
	const char		*ptr;

	if ((ptr = ft_strchr(line, ' ')) == NULL)
		return (0);
	ptr++;
	if ((ptr = ft_strchr(ptr, ' ')) == NULL)
		return (0);
	ptr++;
	if ((ptr = ft_strchr(ptr, ' ')) == NULL)
		return (1);
	return (0);
}

static int			is_room_link_line(char *line)
{
	const char		*ptr;

	if ((ptr = ft_strchr(line, '-')) == NULL)
		return (0);
	ptr++;
	while (*ptr != '\0')
	{
		if (!ft_isalnum(*(ptr++)))
			return (0);
	}
	return (1);
}

int					what_is_this_line(char *line)
{
	size_t			qualifier;

	if ((qualifier = is_comment_line(line)))
		return (qualifier);
	else if (is_number_of_ant_line(line))
		return (NUMBER_OF_ANTS_LINE);
	else if (is_room_name_line(line))
		return (DEFAULT_ROOM_LINE);
	else if (is_room_link_line(line))
		return (ROOM_LINK_LINE);
	return (0);
}