# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhache <jhache@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/08 14:38:11 by jhache            #+#    #+#              #
#    Updated: 2019/07/08 16:48:22 by jhache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Basic definitions
SRC_PATH := src
INC_PATH := include
PARSER_PATH := $(SRC_PATH)/Parser

# Commands
RM := rm -f


# Sources files
YACC_SRC := $(addprefix $(PARSER_PATH)/, Parser.y)
LEX_SRC := $(addprefix $(PARSER_PATH)/, Parser.l)

# Output files
SRC_NAME :=	Parser/Parser.cpp			\
			Parser/lex.yy.cpp

INC_NAME :=	Parser/Parser.tab.h			\
			Parser/location.hh

SRC := $(addprefix $(SRC_PATH)/, $(SRC))
INC := $(addprefix $(INC_PATH)/, $(INC_NAME))

OUT_FILES :=	$(addprefix $(INC_PATH)/, $(INC_NAME)) \
				$(addprefix $(SRC_PATH)/, $(SRC_NAME))


# Parser Compiler
YACC := ~/.brew/opt/bison/bin/bison
LEX := flex

# NB:
# Several files are generated from the same commands. In order to this makefile to not relink,
# we will put a dependencies on only one generated file, but every files will be re-generated on `make` command.
DEPENDENCY := src/Parser/lex.yy.cpp


# Rules
all: cpptarget

cpptarget: $(DEPENDENCY)
	make -f makefile_cpp

$(DEPENDENCY): $(YACC_SRC) $(LEX_SRC)
	$(YACC) -b $(PARSER_PATH)/Parser $(YACC_SRC)
	mv $(PARSER_PATH)/Parser.tab.c src/Parser/Parser.cpp
	mv $(PARSER_PATH)/Parser.tab.h include/Parser/.
	mv $(PARSER_PATH)/location.hh include/Parser/.
	$(LEX) -o src/Parser/lex.yy.c.bad $(LEX_SRC)
	sed 's/register //g' src/Parser/lex.yy.c.bad > src/Parser/lex.yy.cpp
	$(RM) src/Parser/lex.yy.c.bad


testParser:
	make -f makefile_cpp testParser

clean:
	$(RM) $(OUT_FILES)
	make -f makefile_cpp clean

fclean:
	$(RM) $(OUT_FILES)
	make -f makefile_cpp fclean

re: fclean all


.PHONY: all clean fclean re testParser