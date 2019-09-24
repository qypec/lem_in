/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:53:34 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/17 10:54:34 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_lstsize(t_list *alst)
{
	size_t			len;

	len = 0;
	while (alst != NULL)
	{
		len++;
		alst = alst->next;
	}
	return (len);
}
