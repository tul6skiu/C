NAME		= libft.a
INT			= int/
CHAR		= char/
SOURCES		= ft_putchar.c ft_putstr.c ft_strcmp.c \
			ft_strlen.c ft_swap.c ft_memset.c \
			ft_bzero.c ft_memcpy.c ft_memccpy.c \
			ft_memmove.c ft_memchr.c ft_memcmp.c \
			ft_strdup.c ft_strcpy.c ft_strncpy.c \
			ft_strcat.c ft_strncat.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strstr.c \
			ft_strnstr.c ft_strncmp.c ft_atoi.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_isascii.c ft_isprint.c ft_toupper.c \
			ft_tolower.c ft_memalloc.c ft_memdel.c \
			ft_strnew.c ft_strdel.c ft_strclr.c \
			ft_striter.c ft_striteri.c ft_strmap.c \
			ft_strmapi.c ft_strequ.c ft_strnequ.c \
			ft_strsub.c ft_strjoin.c ft_strtrim.c \
			ft_putnbr.c ft_strrev.c ft_strsplit.c \
			ft_itoa.c ft_putendl.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_addstr.c ft_lstnew.c ft_lstdelone.c \
			ft_memlistdel.c ft_lstadd.c ft_putlist.c \
			ft_lstiter.c ft_lstdel.c ft_putlist.c \
			ft_lstcpy.c ft_lstmap.c ft_power.c \
			ft_atoi_base.c ft_atoi_double.c ft_abs.c \
			gnl.c ft_scut.c ft_str_is_lowercase.c \
			ft_alpha_up.c ft_str_is_alpha.c \
			create_mas.c \
			$(INT)clear_int.c $(INT)clear_one_int.c $(INT)coincidence_int.c \
			$(INT)count_int.c $(INT)create_int.c $(INT)lost_int.c \
			$(INT)push_int.c $(INT)put_int.c $(INT)put_one_int.c \
			$(INT)shift_int.c $(INT)unshift_int.c \
			$(CHAR)clear_char.c $(CHAR)clear_one_char.c $(CHAR)coincidence_char.c \
			$(CHAR)count_char.c $(CHAR)create_char.c $(CHAR)lost_char.c \
			$(CHAR)push_char.c $(CHAR)put_char.c $(CHAR)put_one_char.c \
			$(CHAR)shift_char.c $(CHAR)unshift_char.c $(CHAR)str_to_char.c
OBJECTS		= ft_putchar.o ft_putstr.o ft_strcmp.o \
			ft_strlen.o ft_swap.o ft_memset.o \
			ft_bzero.o ft_memcpy.o ft_memccpy.o \
			ft_memmove.o ft_memchr.o ft_memcmp.o \
			ft_strdup.o ft_strcpy.o ft_strncpy.o \
			ft_strcat.o ft_strncat.o ft_strlcat.o \
			ft_strchr.o ft_strrchr.o ft_strstr.o \
			ft_strnstr.o ft_strncmp.o ft_atoi.o \
			ft_isalpha.o ft_isdigit.o ft_isalnum.o \
			ft_isascii.o ft_isprint.o ft_toupper.o \
			ft_tolower.o ft_memalloc.o ft_memdel.o \
			ft_strnew.o ft_strdel.o ft_strclr.o \
			ft_striter.o ft_striteri.o ft_strmap.o \
			ft_strmapi.o ft_strequ.o ft_strnequ.o \
			ft_strsub.o ft_strjoin.o ft_strtrim.o \
			ft_putnbr.o ft_strrev.o ft_strsplit.o \
			ft_itoa.o ft_putendl.o ft_putchar_fd.o \
			ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
			ft_addstr.o ft_lstnew.o ft_lstdelone.o \
			ft_memlistdel.o ft_lstadd.o ft_putlist.o \
			ft_lstiter.o ft_lstdel.o ft_putlist.o \
			ft_lstcpy.o ft_lstmap.o ft_power.o \
			ft_atoi_base.o ft_atoi_double.o ft_abs.o \
			gnl.o ft_scut.o ft_str_is_lowercase.o \
			ft_alpha_up.o ft_str_is_alpha.o \
			create_mas.o \
			clear_int.o clear_one_int.o coincidence_int.o \
			count_int.o create_int.o lost_int.o \
			push_int.o put_int.o put_one_int.o \
			shift_int.o unshift_int.o \
			clear_char.o clear_one_char.o coincidence_char.o \
			count_char.o create_char.o lost_char.o \
			push_char.o put_char.o put_one_char.o \
			shift_char.o unshift_char.o str_to_char.o
FLAGS		= -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SOURCES) -I ./
	ar rc libft.a $(OBJECTS)
	ranlib libft.a
clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f  $(NAME)

re: fclean all
