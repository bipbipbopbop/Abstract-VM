# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <julien@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 09:46:10 by jhache            #+#    #+#              #
#    Updated: 2019/08/08 12:32:00 by julien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -f parser.mk all
	@make -f cpp.mk all

clean:
	@make -f parser.mk clean
	@make -f cpp.mk clean

fclean:
	@make -f parser.mk fclean
	@make -f cpp.mk fclean

re: fclean all


.PHONY: all clean fclean re

# debug
testParser:
	make -f cpp.mk testParser