# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    cpp.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julien <julien@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 13:39:04 by jhache            #+#    #+#              #
#    Updated: 2019/08/08 14:31:18 by julien           ###   ########.fr        #
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
SRC_NAME :=	main.cpp							\
			AbstractVM.cpp
SRC_NAME += Exception/InstructionException.cpp	\
			Exception/OperandValueException.cpp
SRC_NAME += Instruction/Add.cpp					\
			Instruction/Assert.cpp				\
			Instruction/Div.cpp					\
			Instruction/Dump.cpp				\
			Instruction/Exit.cpp				\
			Instruction/Mod.cpp					\
			Instruction/Mul.cpp					\
			Instruction/Pop.cpp					\
			Instruction/Print.cpp				\
			Instruction/Push.cpp				\
			Instruction/Sub.cpp
SRC_NAME += Operand/Operand.cpp					\
			Operand/OperandFactory.cpp			\
			Operand/OperandType.cpp				\
			Operand/OperandValue.cpp
SRC_NAME +=	Parser/lex.yy.cpp					\
			Parser/Parser.cpp					\
			Parser/Driver.cpp

INC_NAME :=	AbstractVM.hpp						\
			InstructionContainer.hpp			\
			VMStack.hpp
INC_NAME += Instruction/Add.hpp					\
			Instruction/Assert.hpp				\
			Instruction/Div.hpp					\
			Instruction/Dump.hpp				\
			Instruction/Exit.hpp				\
			Instruction/IInstruction.hpp		\
			Instruction/Mod.hpp					\
			Instruction/Mul.hpp					\
			Instruction/Pop.hpp					\
			Instruction/Print.hpp				\
			Instruction/Push.hpp				\
			Instruction/Sub.hpp
INC_NAME += Exception/InstructionException.hpp	\
			Exception/OperandValueException.hpp
INC_NAME += Operand/IOperand.hpp				\
			Operand/Operand.hpp					\
			Operand/OperandFactory.hpp			\
			Operand/OperandType.hpp				\
			Operand/OperandValue.hpp
INC_NAME +=	Parser/Parser.tab.h					\
			Parser/Driver.hpp					\
			Parser/location.hh

SRC := $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ := $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.cpp=.o))
INC := $(addprefix $(INC_PATH)/, $(INC_NAME))


OBJ_DIRS := $(sort $(dir $(OBJ)))
INC_DIRS := $(sort $(dir $(INC)))

# Compiler
CC := g++
CCFLAGS := -Wall -Werror -Wextra -std=c++1z
CCFLAGS += -Wno-empty-body
INCFLAGS := $(addprefix -iquote , $(INC_DIRS))
LDFLAGS := -ll


# Rules
all: $(NAME)

$(NAME): $(OBJ_DIRS) $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)


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


testParser:
	$(CC) -c src/Parser/mainParser.cpp -o .bin/Parser/mainParser.o $(CCFLAGS) $(INCFLAGS)
	$(CC) -o Parser $(addprefix $(OBJ_PATH)/, Parser/* Operand/* Instruction/*) -ll


.PHONY: all clean fclean re