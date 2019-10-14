/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:34:29 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/14 21:18:07 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstcpy(t_list *lst, void *(*cpy)(void *))
{
	t_list			*newlst;

	if (lst == NULL)
		return (NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		ft_lstpushback(&newlst, ft_lstnew(cpy(lst->content), \
			lst->content_size));
		lst = lst->next;
	}
	return (newlst);
}
