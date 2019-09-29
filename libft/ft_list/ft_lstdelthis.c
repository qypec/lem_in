/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelthis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:04:21 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/29 10:46:15 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstdelthis(t_list **alst, size_t lstnum, \
											void (*del)(void *, size_t))
{
	while (*alst != NULL && lstnum)
	{
		alst = &(*alst)->next;
		lstnum--;
	}
	if (lstnum == 0 && *alst != NULL)
		ft_lstdelone(alst, del);
}
