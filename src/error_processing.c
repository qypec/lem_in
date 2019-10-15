/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:22:18 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/15 15:57:34 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				error_processing_line(char **line)
{
	ft_strdel(line);
	graphdel(&g_graph);
	ft_putstr("ERROR\n");
	exit(1);
}

void				error_processing(t_list **spath)
{
	ft_lstdel(spath, delfunc_lst__str);
	graphdel(&g_graph);
	ft_putstr("ERROR\n");
	exit(1);
}
