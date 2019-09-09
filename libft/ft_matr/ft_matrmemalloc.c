/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrmemalloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:50:35 by qypec             #+#    #+#             */
/*   Updated: 2019/08/07 12:36:39 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_matrmemalloc(size_t size)
{
	char			**matr;
	int				i;

	if ((matr = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i <= (int)size)
		matr[i++] = NULL;
	return (matr);
}
