/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:25:02 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/14 11:46:18 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_graph				*graphinit(void)
{
	t_graph			*graph;

	if ((graph = (t_graph *)malloc(sizeof(t_graph))) == NULL)
		return (NULL);
	if ((graph->map = ft_mapinit(1000, &roomdel)) == NULL)
	{
		free(graph);
		graph = NULL;
		return (NULL);
	}
	graph->number_of_ants = 0;
	graph->start = NULL;
	graph->end = NULL;
	return (graph);
}

void				graphdel(t_graph **graph)
{
	ft_mapdel(&((*graph)->map));
	(*graph)->number_of_ants = 0;
	ft_strdel(&((*graph)->start));
	ft_strdel(&((*graph)->end));
	free(*graph);
	*graph = NULL;
}
