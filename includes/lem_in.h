/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:16:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/15 13:52:40 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define START_ROOM g_graph->start
# define END_ROOM g_graph->end

# define GET_ROOM(graph, room_name) (t_room *)ft_mapvalue(graph->map, room_name)
# define LINKS_NAME(elem) ((t_links *)((elem)->content))->name

typedef struct		s_way
{
	char			*room;
	size_t			ant;
}					t_way;

typedef struct		s_ways
{
	t_way			*way;
	size_t			length;
	int				ants_q;
	size_t			ants_end;
	size_t			ants;
}					t_ways;

typedef	struct		s_prev
{
	char			*current;
	char			*prev;
}					t_prev;

typedef struct		s_links
{
	char			*name;
	int				wt;
}					t_links;

typedef struct		s_room
{
	int				ant_here;
	int				is_visited;
	t_list			*link;
}					t_room;

typedef struct		s_graph
{
	t_map			*map;
	size_t			number_of_ants;
	char			*start;
	char			*end;
}					t_graph;

t_graph				*g_graph;

void				parsing(void);
t_graph				*graphinit(void);
void				graphdel(t_graph **graph);
t_graph				*graphcpy(t_graph *graph);
t_room				*roominit(void);
void				roomdel(void **room);
t_links				*linksinit(const char *name, int wt);
void				linksdel(void *content, size_t content_size);
t_prev				*prevroom_init(char *current, char *prev_str);
void				del_prevroom(void *content, size_t content_size);

t_list				*create_list_of_paths(void);
t_list				*shortest_path_search(void);
void				redirect_path(t_list *path);
void				add_path_in_sorting_order(t_list **allpaths, \
						t_list *new_path);
void				delete_link(t_list **link, const char *del_link_name);
void				find_optimum_ways(t_list **paths, t_graph *graph);

void				run_ants(t_list *paths);
t_ways				**copy_all_paths(t_list *paths, size_t num_of_paths);
void				calc_ants_queue(t_ways **ways, size_t num_of_paths);
void				set_to_minus_useless_paths(t_ways **ways);
void				delete_array_of_paths(t_ways **ways);

void				print_rooms(t_ways **ways);

void				error_processing_line(char **line);
void				error_processing(t_list	**spath);

#endif
