/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:21:54 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/02 16:59:58 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFF_SIZE 100

int					get_next_line(const int fd, char **line)
{
	t_buff			*buff;
	int				ret;
	char			symb;
	int				reading_status;

	if (fd < 0)
		return (-1);
	if (*line != NULL)
		ft_strdel(line);
	reading_status = 1;
	buff = ft_buffinit(BUFF_SIZE);
	while ((ret = read(fd, &symb, 1)) > 0 && symb != '\n')
	{
		ft_buffaddsymb(buff, symb);
		reading_status++;
	}
	if (ret == -1 || ret == 0)
		reading_status = ret;
	else
		reading_status--;
	*line = ft_strdup(buff->str);
	ft_buffdel(&buff);
	return (reading_status);
}
