# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlister <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 11:11:35 by wlister           #+#    #+#              #
#    Updated: 2018/11/28 11:11:56 by wlister          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a
OBJ 	= $(patsubst %.c, %.o, $(wildcard *.c))
FLAG 	= -Wall -Wextra -Werror
HEADER 	= libft.h 

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAG) -c $< -o $@
clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

		