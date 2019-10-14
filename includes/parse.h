/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:11:59 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/14 12:18:01 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define COMMENT_LINE NULL
# define START_ROOM_LINE &add_start_room
# define END_ROOM_LINE &add_end_room
# define DEFAULT_ROOM_LINE &add_room
# define NUMBER_OF_ANTS_LINE &add_number_of_ants
# define ROOM_LINK_LINE &add_room_link

void				*what_is_this_line(char **line);
int					is_room_name(char *line);
int					is_room_name_line(const char *line);
void				add_room_link(char **line);
void				add_start_room(char **line);
void				add_end_room(char **line);
void				add_room(char **line);
void				add_number_of_ants(char **line);

#endif
