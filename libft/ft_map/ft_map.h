/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:12:31 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/18 13:36:09 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

typedef struct			s_htab
{
	char				*key;
	void				*value;
}						t_htab;

int						hashfunction(const char *str, int size);
t_htab					*init_htab(const char *key, void *value);
void					print_htab(t_htab *htab, void (*printvalue)(void *));

#endif