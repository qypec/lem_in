/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:22:19 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/27 10:50:11 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					main(void)
{	
	//debugging
	g_fd = open("test.map", O_RDONLY);
	//

	if ((g_graph = graphinit()) == NULL)
		return (-1);
	parsing();
	// print_graph();
	algorithm();
	// print_graph();

	graphdel(&g_graph);

	//debugging
	close(g_fd);
	//
}
