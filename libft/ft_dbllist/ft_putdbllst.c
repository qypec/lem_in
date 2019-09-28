/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbllst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:22:05 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/28 18:29:59 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putdbllst(t_dbllist *alst, void (*print)(void *))
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