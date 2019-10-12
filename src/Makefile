# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 21:16:45 by yquaro            #+#    #+#              #
#    Updated: 2019/10/12 18:08:09 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/lem_in.mk

DIR_O = ../lib
SOURCES = main.c parsing.c init.c what_is_line.c error_processing.c \
			add_functions.c shortest_path_search.c debugging.c \
			find_optimum_way.c run_ants.c create_list_of_paths.c \
			jumper__sps.c

OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling lem-in

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
