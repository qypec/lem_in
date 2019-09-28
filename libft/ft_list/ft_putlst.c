/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 09:53:17 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/28 18:30:05 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putlst(t_list *alst, void (*print)(void *))
{
	size_t			i;

	i = 0;
	while (alst != NULL)
	{
		ft_printf("lst-[%zu] content:\n[\n  ", i++);
		print(alst->content);
		ft_printf("\n]");
		ft_printf("\ncontent_size: %d\n\n", alst->content_size);
		alst = alst->next;
	}
}
