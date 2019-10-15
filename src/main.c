/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:22:19 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/15 13:31:01 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					main(void)
{
	t_list			*paths;
	t_graph			*graph_copy;

	if ((g_graph = graphinit()) == NULL)
		return (-1);
	parsing();
	graph_copy = graphcpy(g_graph);
	paths = create_list_of_paths();
	find_optimum_ways(&paths, graph_copy);
	run_ants(paths);
	ft_lstdel(&paths, delfunc_lst__list);
	graphdel(&g_graph);
}
