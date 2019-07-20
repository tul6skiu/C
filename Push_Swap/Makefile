# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlister <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 12:42:13 by wlister           #+#    #+#              #
#    Updated: 2019/01/18 12:42:15 by wlister          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = god

NAME_PUSHSWAP = push_swap
NAME_CHECKER = checker


OBJ_DIR = obj
SRC_DIR = src
INC_DIR = includes/

SRC_PUSHSWAP = push_swap/function_check_sort.c \
	push_swap/function_sort.c \
	push_swap/function_sort2.c \
	push_swap/operation_sorts.c \
	push_swap/operation_sorts2.c \
	push_swap/main.c \
	push_swap/optimiz_func.c \
	push_swap/serch_pivot.c

SRC_CHECKER = checker/check_stack.c \
		checker/check_stack2.c

SRC_OVELAR = ovelar/check_number.c \
		ovelar/creat_stack.c \
		ovelar/ovelar_function.c \
		ovelar/ovelar_function2.c \
		ovelar/ovelar_function3.c 

OBJ_PUSHSWAP = $(addprefix $(OBJ_DIR)/, $(SRC_PUSHSWAP:.c=.o))
OBJ_CHECKER = $(addprefix $(OBJ_DIR)/, $(SRC_CHECKER:.c=.o))
OBJ_OVELAR = $(addprefix $(OBJ_DIR)/, $(SRC_OVELAR:.c=.o))

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT = src/libft/libft.a

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/ovelar
	@mkdir -p $(OBJ_DIR)/push_swap
	@mkdir -p $(OBJ_DIR)/checker

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ_OVELAR) $(OBJ_PUSHSWAP) $(OBJ_CHECKER)
	@$(CC) $(FLAGS) $(OBJ_PUSHSWAP) $(OBJ_OVELAR) -o $(NAME_PUSHSWAP) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ_CHECKER) $(OBJ_OVELAR) -o $(NAME_CHECKER) $(LIBFT)

$(NAME_PUSHSWAP): $(LIBFT) $(OBJ_DIR) $(OBJ_OVELAR) $(OBJ_PUSHSWAP)
	@$(CC) $(FLAGS) $(OBJ_PUSHSWAP) $(OBJ_OVELAR) -o $(NAME_PUSHSWAP) $(LIBFT)

$(NAME_CHECKER): $(LIBFT) $(OBJ_DIR) $(OBJ_OVELAR) $(OBJ_CHECKER)
	@$(CC) $(FLAGS) $(OBJ_CHECKER) $(OBJ_OVELAR) -o $(NAME_CHECKER) $(LIBFT)

$(OBJ_PUSHSWAP): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<

$(OBJ_CHECKER): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<

$(OBJ_OVELAR): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<

$(LIBFT):
	@make -C ./src/libft/

clean:
	@rm -f $(OBJ_PUSHSWAP) $(OBJ_CHECKER) $(OBJ_OVELAR)
	@rm -rf $(OBJ_DIR)
	@make clean -C ./src/libft/

fclean: clean
	@rm -f $(NAME_PUSHSWAP) $(NAME_CHECKER)
	@make fclean -C ./src/libft

re: fclean all