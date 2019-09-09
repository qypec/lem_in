/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:30:22 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/09 16:38:09 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstdelfirst(t_list **head)
{
	t_list			*tmp;

	if (head == NULL)
		return ;
	tmp = *head;
	(*head) = (*head)->next;
	default_lstdel(tmp);
}
