/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:12:13 by wlister           #+#    #+#             */
/*   Updated: 2019/01/10 15:12:14 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_divisible(unsigned long long int nb, int base)
{
	int		count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / base;
		count++;
	}
	return (count);
}

int				ft_multiple(int nb, int st)
{
	while (st > 0)
	{
		nb *= nb;
		st--;
	}
	return (nb);
}

int				ft_convert_bin_to_dec(char *str)
{
	int		size;
	int		i;
	int		res;
	int		n;

	size = (int)ft_strlen(str);
	i = size - 1;
	n = 0;
	res = 0;
	while (i > 0)
	{
		if (str[i] == 1)
			res += ft_multiple(2, n);
		i++;
		n++;
	}
	return (res);
}

char			*ft_convert_to_any_base16(unsigned long long int nb, int base,
									int big)
{
	int		size;
	int		i;
	char	*str;
	char	*digits;
	char	*bigdigits;

	digits = "0123456789abcdef";
	bigdigits = "0123456789ABCDEF";
	size = ft_divisible(nb, base);
	str = ft_strnew(size);
	i = size - 1;
	while (i >= 0)
	{
		if (big == 1)
			str[i] = bigdigits[nb % base];
		else
			str[i] = digits[nb % base];
		nb = nb / base;
		i--;
	}
	return (str);
}

char			*ft_add_prefix(char *str, t_codes *codes)
{
	char	*res;

	if ((codes->spec == 8 || codes->spec == 9) && codes->prec != -1)
	{
		if (codes->spec == 8)
			res = ft_strjoin("0x", str);
		else
			res = ft_strjoin("0X", str);
		ft_strdel(&str);
	}
	else if (codes->spec == 6)
	{
		res = ft_strjoin("0", str);
		ft_strdel(&str);
	}
	else
		res = str;
	return (res);
}
