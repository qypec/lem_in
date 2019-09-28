/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbllstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:46:38 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/28 18:25:42 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dbllist			*ft_dbllstnew(void *content, size_t content_size)
{
	t_dbllist		*list;

	if ((list = (t_dbllist *)malloc(sizeof(t_dbllist))) == NULL)
		return (NULL);
	list->content = content;
	if (list->content != NULL)
		list->content_size = content_size;
	else
		list->content_size = 0;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}
