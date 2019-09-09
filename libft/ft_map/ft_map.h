/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 19:58:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/26 16:06:45 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# define DEFAULT_HASHFUNC &ft_hashfunc

typedef struct			s_htablist
{
	char				*key;
	char				*value;
	struct s_htablist	*next;
}						t_hlist;

t_hlist					*ht_listnew(const char *key, const void *value);
t_hlist					*ht_listdelone(t_hlist *head, t_hlist *dellist);
void					ht_listdel(t_hlist **head);

int						ft_hashfunc(const char *str, int size);

#endif
