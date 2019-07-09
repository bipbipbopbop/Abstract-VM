# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhache <jhache@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 09:46:10 by jhache            #+#    #+#              #
#    Updated: 2019/07/09 09:55:17 by jhache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -f Makefile_parser all
	@make -f Makefile_cpp all

clean:
	@make -f Makefile_parser clean
	@make -f Makefile_cpp clean

fclean:
	@make -f Makefile_parser fclean
	@make -f Makefile_cpp fclean

re: fclean all


.PHONY: all clean fclean re

# debug
testParser:
	make -f Makefile_cpp testParser