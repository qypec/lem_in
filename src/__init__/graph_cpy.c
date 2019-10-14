/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:26:21 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/14 11:27:09 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			*linkscpy(void *content)
{
	return (linksinit(((t_links *)content)->name, ((t_links *)content)->wt));
}

static void			*cpy(void *content)
{
	t_htab			*newcontent;

	newcontent = init_htab(((t_htab *)content)->key, roominit());
	((t_room *)(newcontent->value))->ant_here = \
		((t_room *)(((t_htab *)content)->value))->ant_here;
	((t_room *)(newcontent->value))->is_visited = \
		((t_room *)(((t_htab *)content)->value))->is_visited;
	((t_room *)(newcontent->value))->link = \
		ft_lstcpy(((t_room *)(((t_htab *)content)->value))->link, linkscpy);
	return (newcontent);
}

t_graph				*graphcpy(t_graph *graph)
{
	t_graph			*newgraph;

	if ((newgraph = (t_graph *)malloc(sizeof(t_graph))) == NULL)
		return (NULL);
	newgraph->map = ft_mapcpy(graph->map, cpy);
	newgraph->number_of_ants = graph->number_of_ants;
	newgraph->start = ft_strdup(graph->start);
	newgraph->end = ft_strdup(graph->end);
	return (newgraph);
}
