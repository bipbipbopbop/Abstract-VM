# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhache <jhache@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 13:39:04 by jhache            #+#    #+#              #
#    Updated: 2019/07/03 18:02:42 by jhache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := abstract_vm

# Basic definitions
SRC_PATH := src
OBJ_PATH := .bin
INC_PATH := include

# Commands
RM := rm -f
RMDIR := rm -Rdf
MKDIR := mkdir -p


# Sources files
SRC_NAME :=	main.cpp
SRC_NAME += Operand/Operand.cpp			\
			Operand/OperandType.cpp		\
			Operand/OperandValue.cpp

INC_NAME :=
INC_NAME += Operand/IOperand.hpp	\
			Operand/Operand.hpp		\
			Operand/OperandType.hpp	\
			Operand/OperandValue.hpp

SRC := $(addprefix $(SRC_PATH)/, $(SRC))
OBJ := $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.cpp=.o))
INC := $(addprefix $(INC_PATH)/, $(INC_NAME))

OBJ_DIRS := $(sort $(dir $(OBJ)))
INC_DIRS := $(sort $(dir $(INC)))

# Compiler
CC := g++
CCFLAGS := -Wall -Werror -Wextra -std=c++1z
INCFLAGS := $(addprefix -iquote , $(INC_DIRS))
LDFLAGS :=

#TODO write parser rules
# Parser Compiler
BISON := ~/.brew/opt/bison/bin



# Rules
all: $(NAME)

$(NAME): $(OBJ_DIRS) $(OBJ)
	$(CC) -o $@ $(OBJ)

$(OBJ_DIRS):
	@$(MKDIR) $@

$(OBJ_PATH)/%.o: $(addprefix $(SRC_PATH)/, %.cpp) $(INC)
	$(CC) $(CCFLAGS) $(INCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RMDIR) $(OBJ_DIRS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


parser:
	$(BISON) -b 
#dummy rules for testing
	cd Parser && \
	bison -d test.y && \
	mv test.tab.h test.h && \
	mv test.tab.c test.y.c && \
	flex test.l && \
	mv lex.yy.c test.lex.c && \
	g++ -std=c++1z -c test.lex.c -o test.lex.o -I ../$(INC_PATH)/Operand && \
	g++ -std=c++1z -c test.y.c -o test.y.o -I ../$(INC_PATH)/Operand && \
	g++ -std=c++1z -o test test.lex.o test.y.o -ll -lm -I ../$(INC_PATH)/Operand && \
	cd ..

parserclean:
	cd Parser && \
	$(RM) test test.lex.o test.y.o test.lex.c test.y.c && \
	cd ..


.PHONY: all clean fclean re parser