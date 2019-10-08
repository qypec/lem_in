/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:42:42 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/08 13:46:41 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstnew(void *content, size_t content_size)
{
	t_list				*list;

	if ((list = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->content = content;
	if (list->content != NULL)
		list->content_size = content_size;
	else
		list->content_size = 0;
	list->next = NULL;
	return (list);
}
