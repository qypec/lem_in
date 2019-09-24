/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:04:54 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/16 11:45:33 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;

	if (!s || !f)
		return (NULL);
	if ((newstr = ft_strnew(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	ft_striteri(newstr, (void *)f);
	return (newstr);
}
