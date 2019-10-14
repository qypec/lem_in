# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 12:11:44 by yquaro            #+#    #+#              #
#    Updated: 2019/10/14 12:32:55 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../includes/lem_in.mk

HEADER_H = -I ../../includes/
COMPILING = $(CC) $(CFLAGS) $(HEADER_H)

DIR_O = ../../lib
SOURCES = parsing.c add_functions.c what_is_line.c

OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling parsing 

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@