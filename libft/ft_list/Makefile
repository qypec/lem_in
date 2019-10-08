# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/14 13:54:33 by yquaro            #+#    #+#              #
#    Updated: 2019/10/08 15:37:10 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/libft.mk

SOURCES = ft_lstdel.c ft_lstdelone.c ft_lstnew.c ft_lstadd.c \
			ft_lstpushback.c ft_putlst.c ft_lstdelthis.c ft_lstaddhere.c \
			ft_lstsize.c ft_lstiter.c ft_lstmap.c ft_lstdeltail.c \
			ft_lstcpy.c
OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)
	
print:
	@echo \*\*\* Compiling ft_list

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@

clean:
	@rm -f ../lib/$(OBJECTS)

fclean: clean