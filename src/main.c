/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:22:19 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/11 20:41:27 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//
void				del_elem(void *content, size_t content_size)
{
	ft_strdel((char **)&content);
	content_size = 0;
}

void				del_paths(void *content, size_t content_size)
{
	ft_lstdel((t_list **)&content, del_elem);
	content_size = 0;
}
//


void				*linkscpy(void *content)
{
	return (linksinit(((t_links *)content)->name, ((t_links *)content)->wt));
}

static void			*cpy(void *content)
{
	t_htab			*newcontent;

	newcontent = init_htab(((t_htab *)content)->key, roominit());
	((t_room *)(newcontent->value))->ant_here = ((t_room *)(((t_htab *)content)->value))->ant_here;
	((t_room *)(newcontent->value))->is_visited = ((t_room *)(((t_htab *)content)->value))->is_visited;
	((t_room *)(newcontent->value))->link = ft_lstcpy(((t_room *)(((t_htab *)content)->value))->link, linkscpy);
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

void				add_path_from_min_to_max(t_list **paths, t_list *new_path)
{
	t_list			*paths_tmp;
	size_t			position;

	paths_tmp = (*paths);
	position = 1;
	while (paths_tmp)
	{
		if (paths_tmp->content_size <= new_path->content_size)
		{
			if (paths_tmp->next)
			{
				if (paths_tmp->next->content_size > new_path->content_size)
					position--;
			}
			else
			{
				ft_lstaddhere(paths, ft_lstnew(new_path, g_lstsize), position);
				break ;
			}
		}
		position++;
		paths_tmp = paths_tmp->next;
	}
}

int					main(void)
{	
	t_list		*paths;
	t_list		*path;
	t_list		*first_path;
	t_graph		*graph_copy;

// debugging open file
	// g_fd = open("test.map.optimum_way", O_RDONLY);
//

	paths = NULL;
	if ((g_graph = graphinit()) == NULL)
		return (-1);
	parsing();
	graph_copy = graphcpy(g_graph);
	// print_graph(graph_copy);
	// ft_printf("old:____________________________________________\n");
	if ((first_path = shortest_path_search()) == NULL)
		error_processing(&first_path);
	redirect_path_from_end_to_start(first_path);

	// paths = ft_lstnew(first_path, g_lstsize);

	/*
	** send to lstnew fun list content size, not global size
	*/
	paths = ft_lstnew(first_path, first_path->content_size);
	while ((path = shortest_path_search()) != NULL)
	{
		redirect_path_from_end_to_start(path);
		add_path_from_min_to_max(&paths, path);
	}
	// print_paths(paths);
	// while ((path = shortest_path_search()) != NULL)
	// {
	// 	redirect_path_from_end_to_start(path);
	// 	if (paths->content_size > g_lstsize)
	// 		ft_lstadd(&paths, ft_lstnew(path, g_lstsize));
	// 	else
	// 		ft_lstaddhere(&paths, ft_lstnew(path, g_lstsize), 1);
	// }
	find_optimum_ways(&paths, graph_copy);

// debugging output
	// print_graph(g_graph);
	// ft_printf("graph_copy:____________________________________________\n");
	// print_graph(graph_copy);
	// ft_printf("paths:____________________________________________\n");
	// ft_putlst(paths, &print_paths);
	// print_paths(paths);
//
	// ants_run(paths);
	run_ants(paths);
	// ft_lstdel(&first_path, del_elem);
	ft_lstdel(&paths, del_paths);
	graphdel(&g_graph);

// debugging close file
	// close(g_fd);
//
}
