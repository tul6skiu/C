/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:07:36 by wlister           #+#    #+#             */
/*   Updated: 2019/01/10 16:07:40 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# define CHECK(x) if (x == NULL) return (NULL)

typedef struct				s_codes{
	int						flags[6];
	int						width;
	int						prec;
	int						size;
	int						spec;
	int						sign;
	int						len;
	char					oth;
}							t_codes;

int							ft_printf(const char *format, ...);
int							ft_search_spec(char *str, t_codes *codes);
int							ft_search_size(char *str, t_codes *codes);
int							ft_search_prec(char *str, t_codes *codes);
int							ft_search_width(char *str, t_codes *codes);
int							ft_search_flags(char *str, t_codes *codes);
int							ft_valid_spec(char c, t_codes *codes);
void						ft_struct_zero(t_codes *codes);
int							ft_print_0_spec(t_codes *codes);
int							ft_print_char(int c);
int							ft_print_string(char *str, t_codes *codes);
int							ft_is_flag(char c);
int							ft_is_size(char *str);
int							ft_is_spec(char c, t_codes *codes);
int							ft_is_prec(char *str, t_codes *codes);
int							ft_find_flag(t_codes *codes, int n);
int							ft_convert_bin_to_dec(char *str);
int							ft_parser(char *str, t_codes *codes);
int							ft_print_date(unsigned int nb, t_codes *codes);
int							ft_print_c(va_list ap, t_codes *codes);
int							ft_print_oux(unsigned long long int nb,
										t_codes *codes);
int							ft_print_di(long long int nb, t_codes *codes);
unsigned long long int		ft_get_unsign_number(va_list ap, t_codes *codes);
long long int				ft_get_sign_number(va_list ap, t_codes *codes);
unsigned int				ft_get_char(va_list ap, t_codes *codes);
int							ft_print_sp(va_list ap, t_codes *codes);
char						*ft_apply_modificators(char *str, t_codes *codes);
char						*ft_aplly_width(char *str, t_codes *codes);
char						*ft_expand_prec(char *str, t_codes *codes);
char						*ft_add_zero_before(char *str, int n,
											t_codes *codes);
char						*ft_expand_prec(char *str, t_codes *codes);
char						*ft_convert_to_any_base16(unsigned long long int nb,
													int base, int big);
char						*ft_ll_itoa(long long int nb);
char						*ft_ull_itoa(unsigned long long int nb);
char						*ft_char_into_string(char c, int n);
char						*ft_reduce_prec(char *str, t_codes *codes);
char						*ft_add_prefix(char *str, t_codes *codes);
int							ft_count_unsign_numbers(unsigned long long int n);
int							ft_count_sign_numbers(long long int n);
long long int				ft_sign_size_applicate(long long int nb,
												t_codes *codes);
unsigned long long int		ft_un_si_app(unsigned long long int nb,
										t_codes *codes);
int							ft_string_modificators(char *str, t_codes *codes);
char						*string_to_utf8(unsigned int *code, t_codes *codes);
char						*ft_aplly_plus(char *str, t_codes *codes);
char						*code_to_utf8(unsigned int code);
char						*dtoa(long double n, t_codes *codes);
long double					ft_get_any_double(va_list ap, t_codes *codes);
int							get_len(long long int n, t_codes *codes);
int							ft_print_float(long double nb, t_codes *codes);
char						*dtoa(long double n, t_codes *codes);
int							ft_atoi(const char *str);
void						ft_putchar(char c);
void						ft_putstr(char const *s);
char						*ft_strcpy(char *dst, const char *src);
char						*ft_strdup(const char *s1);
char						*ft_strjoin(char const *s1, char const *s2);
size_t						ft_strlen(const char *s);
char						*ft_strnew(size_t size);
char						*ft_strsub(char const *s, unsigned int start,
									size_t len);
int							ft_toupper(int c);
void						ft_strdel(char **as);
void						*ft_memalloc(size_t size);

#endif
