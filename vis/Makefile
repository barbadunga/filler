# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshagga <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 19:52:36 by mshagga           #+#    #+#              #
#    Updated: 2020/02/15 19:38:45 by mshagga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visualizer

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
IFLAGS = -I $(INC_DIR) -I $(LIBFT_DIR) -I $(BREW_INC)
LFLAGS = -L $(LIBFT_DIR) -lft -L $(BREW_LIB) -lSDL2 -L $(BREW_LIB) -lSDL2_ttf

LIBFT_DIR = ../Libft
INC_DIR = ./inc
OBJ_DIR = ./obj
SRC_DIR = ./src
BREW_INC = $(HOME)/.brew/include
BREW_LIB = $(HOME)/.brew/lib

SRC_LIST =	main.c \
			render.c \
			event_handler.c \
			parser.c \

INC_LIST = visualizer.h
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))

LIBFT = $(LIBFT_DIR)/libft.a
SRC = $(addprefix $(SRC_DIR)/, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_LIST))
INC = $(addprefix $(INC_DIR)/, $(INC_LIST))

all: $(NAME)

$(NAME): $(LIBFT) $(INC) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	$(CC) $(IFLAGS) -c $< -o $@

$(LIBFT):
	make -sC $(LIBFT_DIR)

clean:
	make clean -sC $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean:
	make fclean -sC $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
