/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:42:42 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/09 19:59:34 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list					*ft_lstdelone(t_list *head, t_list *dellist)
{
	t_list				*tmp;
	t_list				*lst;
	void			(*delfunc)(t_list *list);

	if (dellist == NULL)
		return (NULL);
	tmp = head;
	lst = dellist;
	if (tmp == lst)
	{
		head = head->next;
		delfunc = lst->delfunc;
		delfunc(lst);
		lst = head;
		return (lst);
	}
	if (tmp->next != NULL)
	{
		while (tmp->next != lst)
			tmp = tmp->next;
		tmp->next = lst->next;
	}
	delfunc = lst->delfunc;
	delfunc(lst);
	return (head);
}
