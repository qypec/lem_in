# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 11:34:22 by yquaro            #+#    #+#              #
#    Updated: 2019/10/14 13:08:56 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../includes/lem_in.mk

HEADER_H = -I ../../includes/
COMPILING = $(CC) $(CFLAGS) $(HEADER_H)

DIR_O = ../../lib
SOURCES = __init__graph.c __init__links.c __init__room.c graph_cpy.c \
			__init__prevroom.c

OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling __init__

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
