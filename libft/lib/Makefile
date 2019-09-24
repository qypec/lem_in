# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 01:54:46 by yquaro            #+#    #+#              #
#    Updated: 2019/09/10 17:50:22 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all:
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@mv $(NAME) ../$(NAME)
	@echo \*\*\* LIBFT COMPILED!

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)