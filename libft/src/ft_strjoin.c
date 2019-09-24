/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 12:19:30 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/16 11:47:51 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*newstr;
	size_t			j;

	if (!s1 || !s2)
		return (NULL);
	if ((newstr = ft_strnew(sizeof(char) * \
						(ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	j = 0;
	while (*s1 != '\0')
		newstr[j++] = *(s1++);
	while (*s2 != '\0')
		newstr[j++] = *(s2++);
	return (newstr);
}
