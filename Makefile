# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/07 15:01:42 by yquaro            #+#    #+#              #
#    Updated: 2019/09/19 13:39:46 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include includes/lem_in.mk

all:
	@make -C libft/ all
	@mv libft/libft.a lib/libft.a
	@make -C src/ all
	@make -C lib/ all

clean:
	@make -C libft/ clean
	@make -C lib/ clean

fclean: clean
	@make -C libft/ fclean
	@make -C lib/ fclean
	@rm -f $(EXECUTABLE)

re: fclean all
