/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:16:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/10 14:49:12 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include <stdio.h>

# define COMMENT_LINE 1
# define START_ROOM_LINE 2
# define END_ROOM_LINE 3
# define DEFAULT_ROOM_LINE 4
# define NUMBER_OF_ANTS_LINE 5
# define ROOM_LINK_LINE 6

typedef struct		s_room
{
	char			*name;
	t_list			*link;
}					t_room;

int					g_number_of_ants;
t_list				*g_room;

void				parsing(void);

t_room				*init_newroom(char *name, t_list *link);
void				roomdel(t_list *dellist);

#endif
