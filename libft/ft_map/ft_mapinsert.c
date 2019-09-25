/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:15:43 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/25 06:03:46 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

void				ft_mapinsert(t_map *map, const char *key, void *value)
{
	t_list			**maplst;
	void			(*valuedel)(void **);

	maplst = &(map->array[hashfunction(key, map->size)]);
	while (*maplst != NULL)
	{
		if (ft_strequ(((t_htab *)((*maplst)->content))->key, key))
		{
			valuedel = map->valuedel_func;
			valuedel(&(((t_htab *)((*maplst)->content))->value));
			((t_htab *)((*maplst)->content))->value = value;
			return ;
		}
		maplst = &(*maplst)->next;
	}
	*maplst = ft_lstnew(init_htab(key, value), sizeof(t_htab *));
}
