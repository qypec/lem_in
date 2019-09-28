#include "lem_in.h"

void				printlstvalue(void *value)
{
	ft_printf("  name = '%s'\n  wt = '%d'", \
		((t_links *)value)->name, ((t_links *)value)->wt);
}

void				printvalue(void *value)
{
	ft_printf("      ant_here = '%d'\n      links:\n", \
		((t_room *)value)->ant_here);
	ft_putlst(((t_room *)value)->link, printlstvalue);
}

void				print_graph(void)
{
	ft_printf("graph:\n");
	ft_printf("   number of ants: '%d'\n   start room: '%s'\n   end room: '%s'\n", \
		g_graph->number_of_ants, g_graph->start, g_graph->end);
	ft_printf("map:\n");
	ft_putmap(g_graph->map, &printvalue);
}

