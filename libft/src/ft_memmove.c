/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:38:02 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/12 08:43:52 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	tmp[len];
	unsigned char	*tmp_dst;
	size_t			i;

	ft_memcpy(tmp, src, len);
	tmp_dst = (unsigned char *)dst;
	i = 0;
	while (len--)
		*(tmp_dst++) = tmp[i++];
	return (dst);
}
