/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbllstadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:59:52 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/29 08:50:01 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_dbllstadd(t_dbllist **alst, t_dbllist *new)
{
	if (new == NULL)
		return ;
	new->next = *alst;
	new->prev = NULL;
	*alst = new;
}