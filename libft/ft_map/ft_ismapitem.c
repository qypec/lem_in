/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismapitem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 04:45:31 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/07 12:19:02 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "libft.h"

int						ft_ismapitem(t_map *map, const char *key)
{
	int					hash;
	int					(*hash_func)(const char *, int);
	t_hlist				**tmp;

	if (key == NULL)
		return (-1);
	hash_func = map->hashfunc;
	hash = hash_func(key, map->size);
	tmp = &(map->head[hash]);
	if (*tmp == NULL)
		return (-1);
	while (*tmp != NULL)
	{
		if (ft_strcmp((const char *)(*tmp)->key, key) == 0)
			return (hash);
		if ((*tmp)->next == NULL)
			break ;
		tmp = &((*tmp)->next);
	}
	return (-1);
}
