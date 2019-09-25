/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:16:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/25 05:13:03 by yquaro           ###   ########.fr       */
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

typedef struct		s_links
{
	char			*name;
	int				wt;
}					t_links;

typedef struct		s_room
{
	int				ant_here;
	t_list			*link;
}					t_room;

t_map				*g_graph;
size_t				g_number_of_ants; 
char				*g_start;
char				*g_end;

// debagging
int					g_fd;
//

t_room				*roominit(void);
void				roomdel(void **room);
t_links				*linksinit(const char *name, int wt);
void				linksdel(void *content, size_t content_size);

void				parsing(void);
void				*what_is_this_line(char **line);
int					is_room_name(char *line);
int					is_room_name_line(const char *line);
void				add_room_link(char **line);
void				add_start_room(char **line);
void				add_end_room(char **line);
void				add_room(char **line);
void				add_number_of_ants(char **line);

void				error_processing(char **line);

#endif
