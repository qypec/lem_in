#include "lem_in.h"

void				printlstvalue(void *value)
{
	ft_printf("  name = '%s'\n  wt = '%d'", \
		((t_links *)value)->name, ((t_links *)value)->wt);
}

void				printvalue(void *value)
{
	ft_printf("      ant_here = '%d'\n      is_visited: '%d'\n      links\n", \
		((t_room *)value)->ant_here, ((t_room *)value)->is_visited);
	ft_putlst(((t_room *)value)->link, printlstvalue);
}

void				print_graph(t_graph *graph)
{
	ft_printf("graph:\n");
	ft_printf("   number of ants: '%d'\n   start room: '%s'\n   end room: '%s'\n", \
		graph->number_of_ants, graph->start, graph->end);
	ft_printf("map:\n");
	ft_putmap(graph->map, &printvalue);
}

void				put_str(void *content)
{
	ft_putstr((char *)content);
}

void				print_paths(void *content)
{
	ft_putlst((t_list *)content, put_str);
}

	// for (int i = 0; ways[i]->ants_q != -1; i++)
	// {
	// 	ft_printf("PATH NUM: %d LEN %d ANTS %d\n", i, ways[i]->length, ways[i]->ants_q);
	// 	// for (int j = 1; j < ways[i]->length; j++) {
	// 	// 		ft_printf("[%s]", ways[i]->way[j].room);
	// 	// }
	// 	write(1, "\n", 1);
	// }