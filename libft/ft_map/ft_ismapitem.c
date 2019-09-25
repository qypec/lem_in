/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismapitem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:41:43 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/25 06:04:41 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

int					ft_ismapitem(t_map *map, const char *key)
{
	t_list			**maplst;

	maplst = &(map->array[hashfunction(key, map->size)]);
	while (*maplst != NULL)
	{
		if (ft_strequ(((t_htab *)((*maplst)->content))->key, key))
			return (1);
		maplst = &(*maplst)->next;
	}
	return (0);
}
