/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:22:18 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/26 17:36:08 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				error_processing(char **line)
{
	// ft_printf("error line : %s\n", *line);
	ft_strdel(line);
	graphdel(&g_graph);
	ft_printf("ERROR\n");
	exit(1);
}
