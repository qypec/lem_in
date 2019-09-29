/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbllstdelone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:03:07 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/28 21:15:01 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_dbllstdelone(t_dbllist **alst, \
											void (*del)(void *, size_t))
{
	if (alst == NULL)
		return ;
	if (*alst == NULL)
		return ;
	del((*alst)->content, (*alst)->content_size);
	(*alst)->next = NULL;
	(*alst)->prev = NULL;
	free(*alst);
	*alst = NULL;
}
