# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 11:34:22 by yquaro            #+#    #+#              #
#    Updated: 2019/10/14 21:14:12 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../includes/lem_in.mk

HEADER_H = -I ../../includes/
COMPILING = $(CC) $(CFLAGS) $(HEADER_H)

DIR_O = ../../lib
SOURCES = init__graph.c init__links.c init__room.c graph_cpy.c \
			init__prevroom.c

OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling __init__

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
