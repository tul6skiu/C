# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 13:55:33 by afalmer-          #+#    #+#              #
#    Updated: 2018/12/07 13:55:34 by afalmer-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

OBJ = $(patsubst %.c, %.o, $(wildcard *.c))

FLAGS = -Wall -Wextra -Werror

HEADER = fillit.h

HEADERDIR = libft/includes

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME) -I $(HEADERDIR) -L libft/ -lft

%.o: %.c $(HEADER)
	gcc $(FLAGS) -I $(HEADERDIR) -c $< -o $@

$(LIB):
	make -C libft/

clean:
	rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all