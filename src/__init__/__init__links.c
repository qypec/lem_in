/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:28:51 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/14 11:29:11 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_links				*linksinit(const char *name, int wt)
{
	t_links			*link;

	if ((link = (t_links *)malloc(sizeof(t_links))) == NULL)
		return (NULL);
	link->name = ft_strdup(name);
	link->wt = wt;
	return (link);
}

void				linksdel(void *content, size_t content_size)
{
	content_size = 0;
	ft_strdel(&(((t_links *)content)->name));
	((t_links *)content)->wt = 0;
	free(content);
	content = NULL;
}
