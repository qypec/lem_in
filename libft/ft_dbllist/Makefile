# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/14 13:54:33 by yquaro            #+#    #+#              #
#    Updated: 2019/09/28 18:24:00 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/libft.mk

SOURCES = ft_dbllstadd.c ft_dbllstpushback.c ft_dbllstnew.c ft_dbllstdel.c \
			ft_dbllstdelone.c ft_putdbllst.c
OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)
	
print:
	@echo \*\*\* Compiling ft_dbllist

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@

clean:
	@rm -f ../lib/$(OBJECTS)

fclean: clean