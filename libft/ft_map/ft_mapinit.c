/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:06:25 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/25 00:22:45 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

t_map				*ft_mapinit(size_t mapsize, void *valuedel_func)
{
	t_map			*map;
	size_t			i;

	if ((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (NULL);
	map->size = mapsize;
	map->valuedel_func = valuedel_func;
	if ((map->array = (t_list **)malloc(sizeof(t_list *) * (mapsize + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < mapsize)
	{
		map->array[i] = NULL;
		i++;
	}
	return (map);
}
