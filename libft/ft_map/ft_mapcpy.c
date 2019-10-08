/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:29:56 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/08 16:00:25 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

t_map				*ft_mapcpy(t_map *map, void *(*cpy)(void *))
{
	t_map			*newmap;
	size_t			i;

	if (map == NULL)
		return (NULL);
	newmap = ft_mapinit(map->size, map->valuedel_func);
	i = 0;
	while (i < newmap->size)
	{
		newmap->array[i] = ft_lstcpy(map->array[i], cpy);
		i++;
	}
	newmap->array[i] = NULL;
	return (newmap);
}
