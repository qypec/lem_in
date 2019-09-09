# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/02 12:36:22 by yquaro            #+#    #+#              #
#    Updated: 2019/08/28 23:04:26 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/libft.mk

SOURCES = ft_abs.c ft_pow.c
OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)
	
print:
	@echo \*\*\* Compiling ft_math

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@

clean:
	@rm -f ../lib/$(OBJECTS)

fclean: clean