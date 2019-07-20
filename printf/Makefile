# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrestles <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 20:51:58 by vrestles          #+#    #+#              #
#    Updated: 2019/01/13 22:07:20 by wlister          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = src
INC_DIR = includes/
OBJ_DIR = obj

SRC = ft_printf.c \
	itoa/itoa_ll.c \
	itoa/itoa_ull.c \
	libft/ft_atoi.c \
	libft/ft_memalloc.c \
	libft/ft_putchar.c \
	libft/ft_putstr.c \
	libft/ft_strcpy.c \
	libft/ft_strdel.c \
	libft/ft_strdup.c \
	libft/ft_strjoin.c \
	libft/ft_strlen.c \
	libft/ft_strnew.c \
	libft/ft_strsub.c \
	libft/ft_toupper.c \
	modificators/add_plus.c \
	modificators/add_zero.c \
	modificators/other_base.c \
	modificators/precision.c \
	modificators/width.c \
	parser/modificators.c \
	parser/parser.c \
	parser/search_for_parser.c \
	parser/specificator.c \
	print/count_numbers.c \
	print/double_function.c \
	print/get_number.c \
	print/print_c0.c \
	print/print_diouxf.c \
	print/print_sp.c \
	print/print_date.c \
	print/unicode.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/itoa
	@mkdir -p $(OBJ_DIR)/libft
	@mkdir -p $(OBJ_DIR)/modificators
	@mkdir -p $(OBJ_DIR)/parser
	@mkdir -p $(OBJ_DIR)/print

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
