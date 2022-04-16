# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 22:09:55 by acarneir          #+#    #+#              #
#    Updated: 2022/04/16 17:47:44 by acarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror -g

LIBFT_PRINTF_DIR = ./libft/ft_printf
LIBFT_PRINTF = $(LIBFT_PRINTF_DIR)/libftprintf.a



INCLUDE_DIR = ./include
INCLUDE = -I $(INCLUDE_DIR)

SRC_DIR = ./src
SRCS = main.c \
		print_error.c \
		args_utils.c \
		normalize_stack.c \
		push_utils.c \
		sort.c \
		operations.c \
		operations_utils.c \
		sort_utils.c \
		quick_sort.c \
		quick_sort_utils.c \

OBJ_DIR = ./objs
OBJS := $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))


all: $(NAME)

$(NAME): $(LIBFT_PRINTF) $(OBJS)
	$(CC) -lm $(OBJS) $(LIBFT_PRINTF) -o $(NAME)

$(LIBFT_PRINTF):
	make -C $(LIBFT_PRINTF_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean: 
	make clean -C $(LIBFT_PRINTF_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_PRINTF_DIR)
	rm -rf $(NAME)

re : fclean all