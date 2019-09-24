/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdelkey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:20:57 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/18 20:02:39 by yquaro           ###   ########.fr       */
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

void				ft_mapdelkey(t_map **map, const char *key)
{
	void			(*valuedel)(void **);
	t_list			**maplst;
	t_list			*tmp;

	maplst = &((*map)->array[hashfunction(key, (*map)->size)]);
	valuedel = (*map)->valuedel_func;
	while (*maplst != NULL)
	{
		if (ft_strequ(((t_htab *)((*maplst)->content))->key, key))
		{
			valuedel(&(((t_htab *)((*maplst)->content))->value));
			tmp = (*maplst)->next;
			ft_lstdelone(maplst, dellst);
			*maplst = tmp;
			return ;
		}
		maplst = &(*maplst)->next;
	}
}
