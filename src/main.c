/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:22:19 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/14 11:46:41 by yquaro           ###   ########.fr       */
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
	// print_graph(graph_copy);
	// ft_printf("old:____________________________________________\n");
	paths = create_list_of_paths();
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
	// ft_lstdel(&first_path, del_elem);
	ft_lstdel(&paths, del_paths);
	graphdel(&g_graph);

// debugging close file
	// close(g_fd);
//
}
