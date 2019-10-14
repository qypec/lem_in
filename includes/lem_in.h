/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:16:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/14 11:44:07 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define COMMENT_LINE NULL
# define START_ROOM_LINE &add_start_room
# define END_ROOM_LINE &add_end_room
# define DEFAULT_ROOM_LINE &add_room
# define NUMBER_OF_ANTS_LINE &add_number_of_ants
# define ROOM_LINK_LINE &add_room_link

# define START_ROOM g_graph->start
# define END_ROOM g_graph->end

# define GET_ROOM(graph, room_name) (t_room *)ft_mapvalue(graph->map, room_name)
# define LINKS_NAME(elem) ((t_links *)((elem)->content))->name

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

// debugging
int					g_fd;
void				print_graph(t_graph *graph);
//

t_graph				*graphinit(void);
void				graphdel(t_graph **graph);
t_graph				*graphcpy(t_graph *graph);
t_room				*roominit(void);
void				roomdel(void **room);
t_links				*linksinit(const char *name, int wt);
void				linksdel(void *content, size_t content_size);
t_prev				*prev_room_init(char *current, char *prev_str);
void				del_prevroom(void *content, size_t content_size);
void				del_str_from_list(void *content, size_t content_size);

//
void				spath_del(void *str, size_t size);
void				print_paths(void *content);
void				del_elem(void *content, size_t content_size);
void				del_paths(void *content, size_t content_size);
//

void				parsing(void);
void				*what_is_this_line(char **line);
int					is_room_name(char *line);
int					is_room_name_line(const char *line);
void				add_room_link(char **line);
void				add_start_room(char **line);
void				add_end_room(char **line);
void				add_room(char **line);
void				add_number_of_ants(char **line);

t_list				*create_list_of_paths(void);
t_list				*shortest_path_search(void);
void				redirect_path(t_list *path);
void				add_path_in_sorting_order(t_list **allpaths, t_list *new_path);
void				delete_link(t_list **link, const char *del_link_name);
void				find_optimum_ways(t_list **paths, t_graph *graph);

void				ants_run(t_list *paths);
void				run_ants(t_list *paths);

void				error_processing_line(char **line);
void				error_processing(t_list	**spath);

#endif
