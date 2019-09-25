/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:30:21 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/25 06:10:09 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					is_room_name(char *line)
{
	size_t			i;

	i = 0;
	if (line[i] == 'L')
		return (0);
	while (line[i] != '\0' && line[i] != ' ' && line[i] != '-')
	{
		if (!ft_isalnum(line[i]) && line[i] != '_')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (i);
}

void				parsing(void)
{
	char			*line;
	void			(*line_processing)(char **);
	int				ret;

	line = NULL;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ret == 1)
			error_processing(&line);
		if ((line_processing = what_is_this_line(&line)) == COMMENT_LINE)
			continue ;
		line_processing(&line);
	}
	if (g_number_of_ants == 0 || g_start == NULL || g_end == NULL)
		error_processing(&line);
	ft_strdel(&line);
}
