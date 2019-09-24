/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:16:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/23 13:38:53 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define COMMENT_LINE 1
# define START_ROOM_LINE 2
# define END_ROOM_LINE 3
# define DEFAULT_ROOM_LINE 4
# define NUMBER_OF_ANTS_LINE 5
# define ROOM_LINK_LINE 6

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

int					g_fd;

void				parsing(void);
int					what_is_this_line(char *line);
int					is_room_name_line(char *line);
void				error_processing(char **line);

t_room				*roominit(void);
void				roomdel(void **room);
t_links				*linksinit(const char *name, int wt);
void				linksdel(void *content, size_t content_size);

#endif
