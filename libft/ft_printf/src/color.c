/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:23:51 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/10 14:07:55 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void				init_color(void)
{
	g_color = ft_mapnew(NULL, 20);
	ft_mapinsert(g_color, ft_strdup("reset"), ft_strdup(RESET_COLOR_CODE));
	ft_mapinsert(g_color, ft_strdup("red"), ft_strdup(RED_COLOR_CODE));
	ft_mapinsert(g_color, ft_strdup("green"), ft_strdup(GREEN_COLOR_CODE));
	ft_mapinsert(g_color, ft_strdup("yellow"), ft_strdup(YELLOW_COLOR_CODE));
	ft_mapinsert(g_color, ft_strdup("blue"), ft_strdup(BLUE_COLOR_CODE));
	ft_mapinsert(g_color, ft_strdup("magenta"), ft_strdup(MAGENTA_COLOR_CODE));
	ft_mapinsert(g_color, ft_strdup("cyan"), ft_strdup(CYAN_COLOR_CODE));
}

static int			check_param(char *traverse)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (traverse[i] != '}' && traverse[i] != '\0')
	{
		counter++;
		i++;
		if (counter > MAX_COLOR_NAME_SIZE)
			return (0);
	}
	if (traverse[i] == '\0')
		return (0);
	return (counter);
}

void				take_color(char **traverse)
{
	char	*trav;
	char	buff[MAX_COLOR_NAME_SIZE];
	int		n;

	init_color();
	trav = *traverse;
	if ((n = check_param(trav)) == 0)
		return ;
	ft_strncpy(buff, trav + 1, n - 1);
	if (ft_ismapitem(g_color, buff) == -1)
	{
		ft_buffaddsymb(g_output, '{');
		*traverse = trav + 1;
		return ;
	}
	ft_buffadd(g_output, ft_mapvalue(g_color, buff));
	*traverse = trav + n + 1;
	ft_mapdel(&g_color);
}
