/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delfunc__.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 21:13:21 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/14 21:13:24 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					delfunc_lst__str(void *content, size_t content_size)
{
	ft_strdel((char **)&content);
	content_size = 0;
}

void					delfunc_lst__list(void *content, size_t content_size)
{
	ft_lstdel((t_list **)&content, delfunc_lst__str);
	content_size = 0;
}
