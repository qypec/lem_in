/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:22:19 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/14 18:28:39 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					main(void)
{	
	t_list		*paths;
	t_graph		*graph_copy;

// debugging open file
	// g_fd = open("test.map.optimum_way", O_RDONLY);
//

	if ((g_graph = graphinit()) == NULL)
		return (-1);
	parsing();
	graph_copy = graphcpy(g_graph);
	paths = create_list_of_paths();
	// ft_printf("graph_copy:____________________________________________\n");
	find_optimum_ways(&paths, graph_copy);

// debugging output
	// print_graph(g_graph);
	// ft_printf("graph_copy:____________________________________________\n");
	// print_graph(graph_copy);
	// ft_printf("paths:____________________________________________\n");
	// ft_putlst(paths, &print_paths);
	// print_paths(paths);
//

	run_ants(paths);
	ft_lstdel(&paths, __delfunc_lst__list);
	graphdel(&g_graph);

// debugging close file
	// close(g_fd);
//
}
