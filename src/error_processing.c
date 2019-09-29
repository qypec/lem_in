/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:22:18 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/28 20:18:21 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				error_processing_line(char **line)
{
	// ft_printf("error line : %s\n", *line);
	ft_strdel(line);
	graphdel(&g_graph);
	ft_printf("ERROR\n");
	exit(1);
}

void				spath_del(void *str, size_t size)
{
	ft_strdel((char **)&str);
	size = 0;
}

void				error_processing(t_list	**spath)
{
	ft_lstdel(spath, &spath_del);
	graphdel(&g_graph);
	ft_printf("ERROR\n");
	exit(1);
}
