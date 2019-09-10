/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:38:19 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/09 19:58:40 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_lstdel(t_list **head)
{
	t_list				*tmp;
	void				(*delfunc)(t_list *list);

	if (*head == NULL)
		return ;
	tmp = *head;
	while (tmp->next != NULL)
	{
		if ((*head = ft_lstdelone(*head, tmp)) == NULL)
			return ;
		tmp = (*head);
	}
	delfunc = (*head)->delfunc;
	delfunc(*head);
}
