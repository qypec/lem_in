/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jumper__sps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:17:45 by yquaro            #+#    #+#             */
/*   Updated: 2019/10/12 18:09:20 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "jumper__sps.h"

size_t				jumper__sps(size_t method)
{
	static size_t	lstsize = 0;

	if (method == __INIT__)
		lstsize = 0;
	else if (method == INCREMET)
		lstsize++;
	else if (method == GET)
		return (lstsize);
	return (0);
}
