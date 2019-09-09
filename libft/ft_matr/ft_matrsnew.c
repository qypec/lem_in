/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrsnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:38:46 by qypec             #+#    #+#             */
/*   Updated: 2019/08/23 22:01:28 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_matrsnew(size_t matr_size, size_t line_size)
{
	char			**matr;
	int				i;

	if ((matr = (char **)malloc(sizeof(char *) * (matr_size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < (int)matr_size)
	{
		if ((matr[i++] = (char *)ft_memalloc(sizeof(char) * \
												(line_size + 1))) == NULL)
		{
			ft_matrdel(&matr);
			return (NULL);
		}
	}
	matr[i] = NULL;
	return (matr);
}
