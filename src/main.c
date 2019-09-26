/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:22:19 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/26 17:32:37 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					main(void)
{	
	//debugging
	// g_fd = open("test.map", O_RDONLY);
	//

	if ((g_graph = graphinit()) == NULL)
		return (-1);
	parsing();

	graphdel(&g_graph);

	//debugging
	// close(g_fd);
	//
}

// g_graph->map->array[hashfunct(key)]->content->link->content->name