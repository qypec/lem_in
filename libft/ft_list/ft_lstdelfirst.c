/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:30:22 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/09 19:58:43 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstdelfirst(t_list **head)
{
	t_list			*tmp;
	void			(*delfunc)(t_list *list);

	if (head == NULL)
		return ;
	tmp = *head;
	(*head) = (*head)->next;
	delfunc = tmp->delfunc;
	delfunc(tmp);
}
