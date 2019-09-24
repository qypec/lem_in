/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:56:48 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/13 10:45:02 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strdup(const char *str)
{
	char	*new_str;
	int		i;

	if (str == NULL)
		return (NULL);
	if ((new_str = (char *)malloc(sizeof(char) * \
									(ft_strlen(str) + 1))) == NULL)
		return (NULL);
	i = -1;
	while (str[++i] != '\0')
		new_str[i] = str[i];
	new_str[i] = '\0';
	return (new_str);
}
