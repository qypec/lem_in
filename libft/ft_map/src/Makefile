# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/07 13:39:53 by yquaro            #+#    #+#              #
#    Updated: 2019/08/07 14:44:50 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../includes/libft.mk

LIBFT_H = -I ../../includes/
MAP_H = -I ../
COMPILING = $(CC) $(CFLAGS) $(LIBFT_H) $(MAP_H)

DIR_O = ../../lib
SOURCES = ht_list.c ft_hashfunc.c 
OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: $(OBJECTS)
	@true

$(DIR_O)/%.o: %.c
	@$(COMPILING) $< -o $@

clean:
	@rm -f ../../lib/$(OBJECTS)