# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshagga <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/29 17:21:59 by mshagga           #+#    #+#              #
#    Updated: 2020/02/24 21:42:32 by mshagga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -O3 -L $(LIBFT_DIR) -lft -I $(INC_DIR) -I $(LIBFT_DIR)
NAME = mshagga.filler
CC = gcc

LIBFT_DIR = ./Libft
INC_DIR = ./inc
OBJ_DIR = ./obj
SRC_DIR = ./src
PLAYERS_DIR = ./resources/players

SRC_LIST =	main.c \
			init.c \
			lee.c \
			algo.c \
			parser.c \
			queue.c \
			utils.c \

INC_LIST = filler.h
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))

LIBFT = $(LIBFT_DIR)/libft.a
SRC = $(addprefix $(SRC_DIR)/, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_LIST))
INC = $(addprefix $(INC_DIR)/, $(INC_LIST))

all: $(PLAYERS_DIR)/$(NAME)

$(PLAYERS_DIR)/$(NAME): $(LIBFT) $(INC) $(OBJ_DIR) $(OBJ)
	$(CC) $(FLAGS) -o $(PLAYERS_DIR)/$(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	$(CC) -I $(INC_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make -sC $(LIBFT_DIR)

clean:
	make clean -sC $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean:
	make fclean -sC $(LIBFT_DIR)
	rm -f $(PLAYERS_DIR)/$(NAME)

re: fclean all
