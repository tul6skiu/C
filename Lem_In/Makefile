# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/23 13:40:40 by gkoch             #+#    #+#              #
#    Updated: 2019/04/06 22:45:37 by gkoch            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = lem-in

SRC = ./src/
STRUCT = $(SRC)struct/
PARS = $(SRC)pars/
SOLVE = $(SRC)solve/
STREAM = $(SRC)stream/
ALGORITHM = $(SRC)algorithm/
RUN = $(SRC)put_run/

LEM_IN = $(SRC)main.c \
		$(STRUCT)create.c $(STRUCT)unshift.c $(STRUCT)push.c $(STRUCT)clear.c $(STRUCT)del.c $(STRUCT)functions_plus.c\
			$(STRUCT)shift.c \
		$(PARS)lim_read.c $(PARS)tools.c $(PARS)data.c $(PARS)ants.c $(PARS)tag.c $(PARS)coordinates.c \
			$(PARS)mtx.c \
		$(ALGORITHM)solve.c $(ALGORITHM)part1.c $(ALGORITHM)part2.c $(ALGORITHM)del_connecting.c \
		$(RUN)run_ants.c $(RUN)groups.c

DRAW = draw/
READ = read/
CONTROL = control/

# FDF =  $(SRC)$(STRUCT)push.c \
# 		$(SRC)$(DRAW)draw.c $(SRC)$(DRAW)mtrx.c $(SRC)$(DRAW)run_points.c $(SRC)$(DRAW)print.c \
# 		$(SRC)$(READ)read.c \
# 		$(SRC)$(CONTROL)control.c \

ROOT = $(LEM_IN) #$(FDF)
	
	
OBJ=$(ROOT:.c=.o)
CC = clang
CFLAGS = -g #-fsanitize=address #-Wall -Wextra -Werror
LIB = libft/libft.a
LIBDIR = libft/
LIBSPATH = -I libft/ -I /usr/local/include/
HDR = fdf.h
# LINK = -lmlx -framework OpenGL -framework AppKit -L /usr/local/lib/

all: lib $(OBJ) $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(LIBSPATH) -o $(NAME)  $(LIB) $(OBJ)

lib:
	make -C $(LIBDIR)

%.o: %.c $(HDR) $(LIB)
	$(CC) $(CFLAGS) -c $< -o $@ -g

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBDIR) fclean

clean: cleanlib
	/bin/rm -f $(OBJ)

cleanlib:
	make -C $(LIBDIR) clean

re: fclean all
