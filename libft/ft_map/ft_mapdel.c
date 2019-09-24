/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:34:56 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/25 00:31:49 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

void				ft_mapdel(t_map **map)
{
	size_t			i;

	i = 0;
	while (i < (*map)->size)
		ft_mapdelind(map, i++);
	free((*map)->array);
	(*map)->array = NULL;
	(*map)->size = 0;
	(*map)->valuedel_func = NULL;
	free(*map);
	*map = NULL;
}
