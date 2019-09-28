/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbllstpushback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:51:45 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/28 18:16:02 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_dbllstpushback(t_dbllist **alst, t_dbllist *new)
{
	t_dbllist			**prev;

	if (new == NULL)
		return ;
 	while (*alst != NULL)
 	{
 		prev = &(*alst);
    	alst = &(*alst)->next;
 	}
    *alst = new;
    (*alst)->prev = *prev;
}