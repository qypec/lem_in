/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 12:33:27 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/16 12:43:37 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strtrim(char const *s)
{
	char				*newstr;
	size_t				i;

	while (*s != '\0' && ft_isspace(*s))
		s++;
	if ((newstr = ft_strnew(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (ft_isspace(*s) && (!ft_isspace(*(s + 1)) && *(s + 1) != '\0'))
			newstr[i++] = ' ';
		else if (!ft_isspace(*s))
			newstr[i++] = *s;
		s++;
	}
	return (newstr);
}
