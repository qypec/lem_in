/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:23:33 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/03 16:38:28 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstpushback(t_list **alst, t_list *new)
{
	if (new == NULL)
		return ;
 	while (*alst != NULL)
    	alst = &(*alst)->next;
    *alst = new;
}
