# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 21:16:45 by yquaro            #+#    #+#              #
#    Updated: 2019/10/02 17:33:45 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/lem_in.mk

DIR_O = ../lib
SOURCES = main.c parsing.c init.c what_is_line.c error_processing.c \
			add_functions.c shortest_path_search.c redirect.c debugging.c

OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling lem-in

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
