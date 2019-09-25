/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:22:19 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/25 06:07:32 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					main(void)
{
	// g_fd = open("test.map", O_RDONLY);
	g_start = NULL;
	g_end = NULL;
	g_number_of_ants = 0;
	g_graph = ft_mapinit(100, &roomdel);
	parsing();
	// close(g_fd);
}
