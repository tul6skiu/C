/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diouxXf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:26:08 by vrestles          #+#    #+#             */
/*   Updated: 2019/01/10 13:31:00 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_apply_modificators(char *str, t_codes *codes)
{
	char *pres;
	char *wid;
	char *res;

	if (codes->prec > 0)
		pres = ft_expand_prec(str, codes);
	else
		pres = str;
	if (codes->width != 0)
		wid = ft_aplly_width(pres, codes);
	else
		wid = pres;
	if ((codes->spec == 4 || codes->spec == 5) &&
			codes->sign == 0 &&
			(ft_find_flag(codes, 2) || ft_find_flag(codes, 4)))
		res = ft_aplly_plus(wid, codes);
	else
		res = wid;
	return (res);
}

char			*ft_get_oux(unsigned long long int nb, t_codes *codes)
{
	char						*num;
	unsigned long long int		n;

	n = ft_un_si_app(nb, codes);
	if (codes->spec == 6)
		num = ft_convert_to_any_base16(n, 8, 0);
	else if (codes->spec == 8)
		num = ft_convert_to_any_base16(n, 16, 0);
	else if (codes->spec == 9)
		num = ft_convert_to_any_base16(n, 16, 1);
	else if (codes->spec == 11)
		num = ft_convert_to_any_base16(n, 2, 0);
	else
		num = ft_ull_itoa(n);
	return (num);
}

int				ft_print_oux(unsigned long long int nb, t_codes *codes)
{
	char	*res;
	char	*num;
	char	*pref;
	int		count;

	if (codes->prec == -1 && nb == 0 && codes->spec == 6 &&
			ft_find_flag(codes, 5))
		num = ft_char_into_string('0', 1);
	else if (codes->prec == -1 && nb == 0)
		num = ft_strnew(1);
	else
		num = ft_get_oux(nb, codes);
	if (ft_find_flag(codes, 5) && nb != 0)
		pref = ft_add_prefix(num, codes);
	else
		pref = num;
	codes->len = (int)ft_strlen(pref);
	res = ft_apply_modificators(pref, codes);
	count = ft_print_string(res, codes);
	ft_strdel(&res);
	return (count);
}

int				ft_print_di(long long int nb, t_codes *codes)
{
	char			*res;
	char			*num;
	int				count;
	long long int	n;

	if (nb == 0 && codes->prec == -1 && codes->width == 0)
		return (0);
	if (nb == 0 && codes->prec == -1)
		return (ft_string_modificators(ft_strnew(1), codes));
	n = ft_sign_size_applicate(nb, codes);
	codes->len = ft_count_sign_numbers(n);
	if (n < 0)
		codes->sign = 1;
	num = ft_ll_itoa(n);
	res = ft_apply_modificators(num, codes);
	count = ft_print_string(res, codes);
	ft_strdel(&res);
	return (count);
}

int				ft_print_float(long double nb, t_codes *codes)
{
	char	*res;
	char	*bres;
	int		count;
	char	*wid;

	if (nb < 0)
		codes->sign = 1;
	else
		codes->sign = 0;
	bres = dtoa(nb, codes);
	codes->len = (int)ft_strlen(bres);
	if ((codes->width != 0) || (codes->spec == 10))
		wid = ft_aplly_width(bres, codes);
	else
		wid = bres;
	if (codes->sign == 0 && (ft_find_flag(codes, 2) || ft_find_flag(codes, 4)))
		res = ft_aplly_plus(wid, codes);
	else
		res = wid;
	count = ft_print_string(res, codes);
	ft_strdel(&res);
	return (count);
}
