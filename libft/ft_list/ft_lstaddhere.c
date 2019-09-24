/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddhere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:40:31 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/17 10:49:42 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstaddhere(t_list **alst, t_list *new, size_t position)
{
	while (*alst != NULL && position)
	{
		alst = &(*alst)->next;
		position--;
	}
	if (position == 0)
	{
		new->next = *alst;
		*alst = new;
	}
}