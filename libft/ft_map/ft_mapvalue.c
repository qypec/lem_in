/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 14:57:51 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/07 15:46:22 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "libft.h"

const char			*ft_mapvalue(const t_map *map, const char *key)
{
	int					hash;
	int					(*hash_func)(const char *, int);
	t_hlist				*tmp;

	hash_func = map->hashfunc;
	hash = hash_func(key, map->size);
	tmp = map->head[hash];
	if (tmp == NULL)
		return (NULL);
	while (tmp != NULL)
	{
		if (ft_strcmp((const char *)tmp->key, key) == 0)
			return ((const char *)tmp->value);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	return (NULL);
}
