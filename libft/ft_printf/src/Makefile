# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 14:07:18 by yquaro            #+#    #+#              #
#    Updated: 2019/08/07 14:45:30 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../includes/libft.mk

LIBFT_H = -I ../../includes/
PRINTF_H = -I ../
COMPILING = $(CC) $(CFLAGS) $(LIBFT_H) $(PRINTF_H)

DIR_O = ../../lib
SOURCES = color.c print_arg.c init_part.c print_date.c parse.c struct_spec.c \
			is_it_something.c init_width.c print_diu.c ft_itoa_base.c \
			print_char.c print_dl_dll.c print_int.c print_float.c \
			display_int.c gspec.c rounding.c ft_fill_part.c print_matrix.c
OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: $(OBJECTS)
	@true
	
$(DIR_O)/%.o: %.c
	@$(COMPILING) $< -o $@

clean:
	@rm -f ../../lib/$(OBJECTS)
	