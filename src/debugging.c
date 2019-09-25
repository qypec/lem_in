#include "libft.h"

void				printlstvalue(void *value)
{
	ft_printf("name = %s\nwt = %d\n", ((t_links *)value)->name, ((t_links *)value)->wt);
}

void				printvalue(void *value)
{
	ft_printf("ant_here = %d\n", ((t_room *)value)->ant_here);
	ft_lstprint(((t_room *)value)->link, printlstvalue);
}

