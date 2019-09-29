/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:05:21 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/29 14:44:45 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <time.h>
# include <unistd.h>

/*
** ft_alloc
*/

void					*ft_realloc(void *ptr, size_t newsize);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
void					ft_strdel(char **as);

/*
** ft_buffer
*/

typedef struct			s_buff
{
	char				*str;
	int					i;
	int					totalsize;
	int					additional_size;
}						t_buff;

t_buff					*ft_buffinit(int size);
void					ft_buffaddsymb(t_buff *buff, char c);
void					ft_buffadd(t_buff *buff, const char *str);
void					ft_buffladd(t_buff *buff, const char *str, int len);
void					ft_buffdel(t_buff **buff);

/*
** ft_ctime
*/

# include "../ft_ctime/ft_ctime.h"

char					*ft_ctime(const time_t *ttime);
t_cdate					*ft_uctime(const time_t *ttime);
void					free_uctime(t_cdate *date);

/*
** ft_list
*/

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

t_list					*ft_lstnew(void *content, size_t content_size);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstaddhere(t_list **alst, t_list *new, size_t position);
void					ft_lstpushback(t_list **alst, t_list *new);
void					*ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelthis(t_list **alst, size_t lstnum, \
													void (*del)(void *, size_t));
void					ft_lstdeltail(t_list **alst, void (*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_putlst(t_list *alst, void (*print)(void *));
size_t					ft_lstsize(t_list *alst);

/*
** ft_dbllist
*/

typedef struct			s_dbllist
{
	void				*content;
	size_t				content_size;
	struct s_dbllist	*next;
	struct s_dbllist	*prev;
}						t_dbllist;

t_dbllist				*ft_dbllstnew(void *content, size_t content_size);
void					ft_dbllstadd(t_dbllist **alst, t_dbllist *new);
void					ft_dbllstpushback(t_dbllist **alst, t_dbllist *new);
void					ft_dbllstdel(t_dbllist **alst, \
										void (*del)(void *, size_t));
void					ft_dbllstdelone(t_dbllist **alst, \
											void (*del)(void *, size_t));
void					ft_putdbllst(t_dbllist *alst, void (*print)(void *));

/*
** ft_map
*/

# include "../ft_map/ft_map.h"

typedef struct			s_map
{
	t_list				**array;
	size_t				size;
	void				*valuedel_func;
}						t_map;

t_map				*ft_mapinit(size_t mapsize, void *valuedel_func);
void				ft_mapinsert(t_map *map, const char *key, void *value);
int					ft_ismapitem(t_map *map, const char *key);
const void			*ft_mapvalue(t_map *map, const char *key);
void				ft_mapdel(t_map **map);
void				ft_mapdelind(t_map **map, size_t index);
void				ft_mapdelkey(t_map **map, const char *key);
void				ft_putmap(t_map *map, void (*printvalue)(void *));

/*
** ft_math
*/

# define ROUND_DOWN(number) ((int)number)

int						ft_abs(int num);
int						ft_pow(int num, int power);

/*
** ft_matr
*/

char					**ft_matrsnew(size_t matr_size, size_t line_size);
char					**ft_matrmemalloc(size_t size);
char					**ft_matrnew(const char *first_str, ...);
char					**ft_matrdup(const char **matr);
void					ft_strswap(char **matr, int first, int second);
void					*ft_matrdel(char ***ret);
size_t					ft_matrlen(const char **matr);

/*
** ft_printf
*/

# include "../ft_printf/ft_printf.h"

int						ft_printf(const char *format, ...);

/*
** other functions
*/

int						get_next_line(const int fd, char **line);
void					*ft_memset (void *destination, int c, size_t n);
void					*ft_bzero (void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, \
														int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *arr, int c, size_t n);
int						ft_memcmp(const void *arr1, const void *arr2, size_t n);
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *str);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *str, const char *tail);
char					*ft_strncat(char *str, const char *tail, size_t n);
const char				*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, \
										char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start, \
																size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(long long n);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
int						ft_isspace(int c);
int						ft_numblen(long long n);
char					*ft_strncut(char *str, int n, char *choice);
char					*ft_strencut(char *str, int n, char *choice);
char					*ft_addsymb(char *str, char c, int num);
char					*ft_addsymbend(char *str, char c, int num);
void					ft_strglue(char *puthere, ...);
void					ft_strlglue(int start, char *puthere, ...);
char					*ft_stradd(char *str, char c);
size_t					ft_matrlen(const char **matr);
int						ft_isempty(const char *str);

#endif
