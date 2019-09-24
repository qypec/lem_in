/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_htab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:00:20 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/18 11:31:01 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_map.h"

void				print_htab(t_htab *htab, void (*printvalue)(void *))
{
	ft_printf("key : %s\n  value:\n", htab->key);
	printvalue(htab->value);
}
