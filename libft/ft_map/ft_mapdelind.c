/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdelind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:36:17 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/18 19:55:48 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

static void			dellst(void *content, size_t content_size)
{
	ft_strdel(&(((t_htab *)content)->key));
	content_size = 0;
	free(content);
	content = NULL;
}

void				ft_mapdelind(t_map **map, size_t index)
{
	void			(*valuedel)(void **);
	t_list			**maplst;
	t_list			*tmp;

	if (index > (*map)->size)
		return ;
	if ((*map)->array[index] == NULL)
		return ;
	maplst = &((*map)->array[index]);
	valuedel = (*map)->valuedel_func;
	while (*maplst != NULL)
	{
		valuedel(&(((t_htab *)((*maplst)->content))->value));
		tmp = (*maplst)->next;
		ft_lstdelone(maplst, dellst);
		*maplst = tmp;
	}
	(*map)->array[index] = NULL;
}
