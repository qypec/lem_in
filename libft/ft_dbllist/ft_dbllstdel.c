/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbllstdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:02:44 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/28 20:19:10 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_dbllstdel(t_dbllist **alst, \
										void (*del)(void *, size_t))
{
	t_dbllist			*tmp;
	t_dbllist			*position;

	position = (*alst)->prev;
	while (*alst != NULL)
	{
		tmp = (*alst)->next;
		ft_dbllstdelone(alst, del);
		*alst = tmp;
	}
	*alst = position;
	while (*alst != NULL)
	{
		tmp = (*alst)->prev;
		ft_dbllstdelone(alst, del);
		*alst = tmp;
	}
}
