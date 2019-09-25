/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:22:18 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/25 06:23:33 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				error_processing(char **line)
{
	// ft_printf("error line : %s\n", *line);
	ft_strdel(line);
	ft_strdel(&g_start);
	ft_strdel(&g_end);
	ft_mapdel(&g_graph);
	ft_printf("ERROR\n");
	exit(1);
}
