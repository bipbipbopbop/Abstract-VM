# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhache <jhache@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 13:39:04 by jhache            #+#    #+#              #
#    Updated: 2019/06/25 13:53:34 by jhache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := abstract_vm

# Basic definitions
SRC_PATH := src
OBJ_PATH := .bin
INC_PATH := include

# Compiler
CC := g++
CCFLAGS := -Wall -Werror -Wextra
INCFLAGS := -iquote $(INC_PATH)
LDFLAGS :=


# Commands
RM := rm -f
RMDIR := rm -Rdf
MKDIR := mkdir -p


# Sources files
SRC_NAME :=	main.cpp

INC_NAME :=


SRC := $(addprefix $(SRC_PATH)/, $(SRC))
OBJ := $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.cpp=.o))
INC := $(addprefix $(INC_PATH)/, $(INC_NAME))

OBJ_DIRS := $(sort $(dir $(OBJ)))

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


.PHONY: all clean fclean re libraries