# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 21:16:45 by yquaro            #+#    #+#              #
#    Updated: 2019/09/09 19:23:49 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/lem_in.mk

DIR_O = ../lib
SOURCES = main.c
OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling lem-in

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
