# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/07 13:29:16 by yquaro            #+#    #+#              #
#    Updated: 2019/08/07 14:45:41 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../includes/libft.mk

LIBFT_H = -I ../../includes/
CTIME_H = -I ../
COMPILING = $(CC) $(CFLAGS) $(LIBFT_H) $(CTIME_H)

DIR_O = ../../lib
SOURCES = getdata.c getmonth.c get_temporarydata.c struct_to_str.c
OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: $(OBJECTS)
	@true

$(DIR_O)/%.o: %.c
	@$(COMPILING) $< -o $@

clean:
	@rm -f ../../lib/$(OBJECTS)
