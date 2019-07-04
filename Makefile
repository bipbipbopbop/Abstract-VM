# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhache <jhache@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 13:39:04 by jhache            #+#    #+#              #
#    Updated: 2019/07/04 17:34:10 by jhache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := abstract_vm

# Basic definitions
SRC_PATH := src
OBJ_PATH := .bin
INC_PATH := include
PARSER_PATH := $(SRC_PATH)/Parser

# Commands
RM := rm -f
RMDIR := rm -Rdf
MKDIR := mkdir -p


# Sources files
SRC_NAME :=	main.cpp
SRC_NAME += Operand/Operand.cpp			\
			Operand/OperandType.cpp		\
			Operand/OperandValue.cpp
SRC_NAME +=	Parser/lex.yy.cpp			\
			Parser/Parser.cpp			\
			Parser/Driver.cpp

INC_NAME :=
INC_NAME += Operand/IOperand.hpp		\
			Operand/Operand.hpp			\
			Operand/OperandType.hpp		\
			Operand/OperandValue.hpp
INC_NAME +=	Parser/Parser.tab.h			\
			Parser/Driver.hpp			\
			Parser/location.hh


SRC := $(addprefix $(SRC_PATH)/, $(SRC))
OBJ := $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.cpp=.o))
INC := $(addprefix $(INC_PATH)/, $(INC_NAME))

# Parser files
YACC_SRC := $(addprefix $(PARSER_PATH)/, Parser.y)
LEX_SRC := $(addprefix $(PARSER_PATH)/, Parser.l)

PARSER_FILES :=	$(addprefix $(INC_PATH)/Parser/, Parser.tab.h location.hh)	\
				$(addprefix $(PARSER_PATH)/, Parser.cpp lex.yy.cpp)

OBJ_DIRS := $(sort $(dir $(OBJ)))
INC_DIRS := $(sort $(dir $(INC)))

# Compiler
CC := g++
CCFLAGS := -Wall -Werror -Wextra -std=c++1z
INCFLAGS := $(addprefix -iquote , $(INC_DIRS))
LDFLAGS := -ll

# Parser Compiler
YACC := ~/.brew/opt/bison/bin/bison
LEX := flex


# Rules
all: debug $(NAME)

debug:

$(NAME): parser $(OBJ_DIRS) $(OBJ)
	$(CC) -o $@ $(LDFLAGS) $(OBJ)

$(OBJ_DIRS):
	@$(MKDIR) $@

$(OBJ_PATH)/%.o: $(addprefix $(SRC_PATH)/, %.cpp) $(INC)
	$(CC) $(CCFLAGS) $(INCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RMDIR) $(OBJ_DIRS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(PARSER_FILES)

re: fclean all


parser: $(YACC_SRC) $(LEX_SRC)
	$(YACC) -b $(PARSER_PATH)/Parser $(YACC_SRC)
	mv $(PARSER_PATH)/Parser.tab.c src/Parser/Parser.cpp
	mv $(PARSER_PATH)/Parser.tab.h include/Parser/.
	mv $(PARSER_PATH)/location.hh include/Parser/.
	$(LEX) -o src/Parser/lex.yy.c.bad $(LEX_SRC)
	sed 's/register //g' src/Parser/lex.yy.c.bad > $(SRC_PATH)/Parser/lex.yy.cpp
	$(RM) src/Parser/lex.yy.c.bad

testParser:
	$(CC) -c src/Parser/mainParser.cpp -o .bin/Parser/mainParser.o $(CCFLAGS) $(INCFLAGS)
	$(CC) -o Parser $(addprefix $(OBJ_PATH)/, Parser/* Operand/*) -ll


.PHONY: all clean fclean re parser testParser