/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:49:53 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/16 11:02:13 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *haystack, \
									const char *needle, size_t n)
{
	size_t			i;
	const char		*tmp;

	if (n == 0)
		return ((char *)haystack);
	while (*haystack != '\0' && n--)
	{
		i = 0;
		tmp = haystack;
		while (i <= n && *(tmp++) == needle[i])
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
