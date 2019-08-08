# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parser.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <julien@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/08 14:38:11 by jhache            #+#    #+#              #
#    Updated: 2019/08/08 13:03:42 by julien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Basic definitions
SRC_PATH := src
INC_PATH := include
PARSER_PATH := $(SRC_PATH)/Parser

# Commands
RM := rm -f

# OS detection
UNAME_S := $(shell uname -s)


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
ifeq ($(UNAME_S), Linux)
	YACC := /usr/local/bin/bison
else
	YACC := ~/.brew/opt/bison/bin/bison
endif
LEX := flex


# NB:
# Several files are generated from the same commands. In order to not relink with this makefile,
# we will put a dependencies on only one generated file, but every files will be re-generated on `make` command.
DEPENDENCY := src/Parser/lex.yy.cpp


# Rules
all: $(DEPENDENCY)

$(DEPENDENCY): $(YACC_SRC) $(LEX_SRC)
	$(YACC) -b $(PARSER_PATH)/Parser $(YACC_SRC)
	mv $(PARSER_PATH)/Parser.tab.c src/Parser/Parser.cpp
	mv $(PARSER_PATH)/Parser.tab.h include/Parser/.
	mv $(PARSER_PATH)/location.hh include/Parser/.
	$(LEX) -o src/Parser/lex.yy.c.bad $(LEX_SRC)
	sed 's/register //g' src/Parser/lex.yy.c.bad > src/Parser/lex.yy.cpp
	$(RM) src/Parser/lex.yy.c.bad

clean:
	$(RM) $(OUT_FILES)

fclean: clean

re: fclean all


.PHONY: all clean fclean re testParser