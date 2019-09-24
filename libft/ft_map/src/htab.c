/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:34:12 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/18 11:55:26 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

t_htab				*init_htab(const char *key, void *value)
{
	t_htab			*htab;

	if ((htab = (t_htab *)malloc(sizeof(t_htab))) == NULL)
		return (NULL);
	if ((htab->key = ft_strdup(key)) == NULL)
	{
		free(htab);
		return (NULL);
	}
	htab->value = value;
	return (htab);
}
