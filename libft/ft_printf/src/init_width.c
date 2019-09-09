/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:47:58 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/07 12:44:00 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void				init_width(void)
{
	if (g_width == NULL)
		if ((g_width = malloc(sizeof(t_width))) == NULL)
			exit(-1);
	g_width->space_left = 0;
	g_width->zero = 0;
	g_width->space_right = 0;
	g_width->width = 0;
}

void				widthfree(void)
{
	if (g_width == NULL)
		return ;
	g_width->space_left = 0;
	g_width->zero = 0;
	g_width->space_right = 0;
	g_width->width = 0;
	free(g_width);
	g_width = NULL;
}
