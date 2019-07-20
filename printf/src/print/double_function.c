/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:54:51 by wlister           #+#    #+#             */
/*   Updated: 2019/01/08 17:54:57 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			is_neg_n(double n)
{
	char	*p;

	p = (char *)&n;
	p = p + sizeof(double) - 1;
	return ((*p >> 7) & 1);
}

static void			fill_int_p(char *res, long long int n, int ind,
							t_codes *codes)
{
	if (n == 0 && !codes->sign)
	{
		res[ind] = 0 + 48;
		return ;
	}
	if (codes->sign)
	{
		res[ind] = -(n % 10) + 48;
		n /= 10;
		n = -n;
		ind--;
		res[0] = '-';
	}
	while (n > 0)
	{
		res[ind] = n % 10 + 48;
		n /= 10;
		ind--;
	}
}

static void			round_frac_p(char *res, int end, int flag)
{
	int		tmp;
	int		rnd;

	rnd = flag > 50 ? 1 : 0;
	while (rnd != 0 && end >= 0)
	{
		if (res[end] != '.')
		{
			tmp = (res[end] - '0') + rnd;
			res[end] = tmp % 10 + 48;
			rnd = tmp / 10;
		}
		end--;
	}
}

static void			fill_frac_p(char *res, double n, int ind, int prec)
{
	int		end;

	end = ind + prec - 1;
	while (prec > 0)
	{
		res[ind] = (int)(n * 10) + 48;
		n *= 10;
		n -= (int)n;
		ind++;
		prec--;
	}
	round_frac_p(res, end, (int)(n * 100));
}

char				*dtoa(long double n, t_codes *codes)
{
	char			*res;
	int				size;
	long long int	int_p;
	double			frac_p;
	int				prec;

	prec = codes->prec == 0 ? 6 : codes->prec;
	codes->sign = is_neg_n(n);
	int_p = (long long int)n;
	frac_p = n - int_p;
	size = get_len(int_p, codes) + 1 + prec + 1;
	res = (char*)malloc(sizeof(char) * size);
	res[size - prec - 1 - 1] = '.';
	res[size - 1] = '\0';
	fill_int_p(res, int_p, size - prec - 1 - 1 - 1, codes);
	fill_frac_p(res, codes->sign ? -frac_p : frac_p, size - prec - 1, prec);
	return (res);
}
