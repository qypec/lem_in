/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _delfunc_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:29:53 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/14 11:33:58 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//
void				del_elem(void *content, size_t content_size)
{
	ft_strdel((char **)&content);
	content_size = 0;
}

void				del_paths(void *content, size_t content_size)
{
	ft_lstdel((t_list **)&content, del_elem);
	content_size = 0;
}
//

void				del_str_from_list(void *content, size_t content_size)
{
	ft_strdel((char **)&content);
	content_size = 0;
}
