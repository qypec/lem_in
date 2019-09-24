/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeltail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:37:34 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/17 15:41:17 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstdeltail(t_list **alst, void (*del)(void *, size_t))
{
	while ((*alst)->next != NULL)
    	alst = &(*alst)->next;
    ft_lstdelone(alst, del);
}
