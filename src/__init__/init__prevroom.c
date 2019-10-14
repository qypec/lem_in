/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__prevroom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:08:23 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/14 13:09:50 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_prev				*prevroom_init(char *current, char *prev_str)
{
	t_prev			*prev;

	if ((prev = (t_prev *)malloc(sizeof(t_prev))) == NULL)
		return (NULL);
	prev->current = ft_strdup(current);
	prev->prev = ft_strdup(prev_str);
	return (prev);
}

void				del_prevroom(void *content, size_t content_size)
{
	ft_strdel(&((t_prev *)(content))->current);
	ft_strdel(&((t_prev *)(content))->prev);
	free(content);
	content = NULL;
	content_size = 0;
}
