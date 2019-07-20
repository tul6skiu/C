/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 02:55:37 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 21:03:37 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_addstr(const char *str);
void				ft_putchar(char c);
void				ft_putnbr(int nb);
void				ft_putstr(const char *str);
void				ft_strrev(char *s);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *str);
void				ft_swap(int *a, int *b);
void				*ft_memset(void *s, int c, size_t count);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *destptr, const void *srcptr, size_t num);
void				*ft_memccpy(void *dest, const void *src, int c, size_t num);
void				*ft_memmove(void *dest, const void *src, size_t count);
void				*ft_memchr(const void *s, int c, size_t num);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t nb);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int nbr);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_memlistdel(void *ap, size_t ap_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_putlist(t_list	*lst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstcpy(t_list *list);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
double				ft_power(double nb, int power);
int					ft_atoi_base(char *str, char *base);
double				ft_atoi_double(const char *str);
int					ft_abs(int i);
int					gnl(const int fd, char **line);
char				*ft_scut(char const *s, unsigned int start, char c);
int					ft_str_is_lowercase(char *str);
void				ft_alpha_up(char **str);
int					ft_str_is_alpha(char c);
int					*create_mas(int len);
/*
** --------------------------- Work INT mas ---------------------------------
*/
typedef struct		s_int
{
	int				integer;
	struct s_int	*next;
}					t_int;

t_int				*create_int(int integer);
int					push_int(t_int **begin_list, t_int *data);
int					unshift_int(t_int **begin_list, t_int *data);
int					shift_int(t_int **integer);
t_int				*coincidence_int(t_int *integer, int coincidence);
void				clear_one_int(t_int **integer);
void				clear_int(t_int **integer);
void				put_int(t_int *integer);
int					count_int(t_int *integer);
t_int				*lost_int(t_int *integer);
void				put_one_int(t_int *integer);
/*
** --------------------------- Work CHAR mas ---------------------------------
*/
typedef struct		s_char
{
	int				letter;
	struct s_char	*next;
}					t_char;

t_char				*create_char(int integer);
int					push_char(t_char **begin_list, t_char *data);
int					unshift_char(t_char **begin_list, t_char *data);
char				shift_char(t_char **integer);
t_char				*coincidence_char(t_char *integer, int coincidence);
void				clear_one_char(t_char **integer);
void				clear_char(t_char **integer);
void				put_char(t_char *integer);
int					count_char(t_char *integer);
t_char				*lost_char(t_char *integer);
void				put_one_char(t_char *integer);
t_char				*str_to_char(char *str);

#endif
