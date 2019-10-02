/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:22:19 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/02 17:21:54 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					main(void)
{	
	t_list		*paths;
	t_list		*first_path;

// debugging open file
	// g_fd = open("test.map", O_RDONLY);
//

	paths = NULL;
	if ((g_graph = graphinit()) == NULL)
		return (-1);
	parsing();
	if ((first_path = shortest_path_search()) == NULL)
		error_processing(&first_path);
	// redirect_path_from_end_to_start(first_path);

	// paths = ft_lstnew(first_path, sizeof(t_list *));
	// while ((path = shortest_path_search()) != NULL)
	// {
	// 	redirect_path_from_end_to_start(path);
	// 	ft_lstadd(&paths, ft_lstnew(path, sizeof(t_list *)));
	// }
	// paths = find_optimum_ways(&paths);
	// ants_run(paths);

// debugging output
	print_graph();
	// ft_printf("paths:\n");
	// ft_putlst(paths, &print);
//

	// ft_lstdel(&paths, );
	graphdel(&g_graph);

// debugging close file
	// close(g_fd);
//
}
