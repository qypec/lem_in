/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __delfunc__.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:54:44 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/14 11:57:57 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					__delfunc_lst__str(void *content, size_t content_size)
{
	ft_strdel((char **)&content);
	content_size = 0;
}

void					__delfunc_lst__list(void *content, size_t content_size)
{
	ft_lstdel((t_list **)&content, __delfunc_lst__str);
	content_size = 0;
}
