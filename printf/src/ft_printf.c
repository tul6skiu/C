/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:14:01 by vrestles          #+#    #+#             */
/*   Updated: 2019/01/10 14:14:19 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_print_string(char *str, t_codes *codes)
{
	int	count;

	count = 0;
	while (*str)
	{
		ft_putchar(*str);
		count++;
		str++;
	}
	if (codes->spec == 1 && codes->len == 0)
	{
		ft_putchar('\0');
		count++;
	}
	return (count);
}

void			ft_struct_zero(t_codes *codes)
{
	codes->flags[0] = 0;
	codes->flags[1] = 0;
	codes->flags[2] = 0;
	codes->flags[3] = 0;
	codes->flags[4] = 0;
	codes->flags[5] = 0;
	codes->size = 0;
	codes->spec = 0;
	codes->prec = 0;
	codes->width = 0;
	codes->sign = 0;
	codes->len = 0;
	codes->oth = 0;
}

static int		ft_print_anything(va_list ap, t_codes *codes)
{
	int count;

	count = 0;
	if (codes->spec == 0 || codes->spec == 1)
		count += ft_print_c(ap, codes);
	if (codes->spec == 2 || codes->spec == 3)
		count += ft_print_sp(ap, codes);
	if (codes->spec == 4 || codes->spec == 5)
		count += ft_print_di(ft_get_sign_number(ap, codes), codes);
	if ((codes->spec >= 6 && codes->spec <= 9) || codes->spec == 11)
		count += ft_print_oux(ft_get_unsign_number(ap, codes), codes);
	if (codes->spec == 10)
		count += ft_print_float(ft_get_any_double(ap, codes), codes);
	if (codes->spec == 12)
		count += ft_print_date(va_arg(ap, unsigned int), codes);
	return (count);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*str;
	int			count;
	int			offset;
	t_codes		codes;

	count = 0;
	va_start(ap, format);
	str = (char *)format;
	while (*str)
	{
		if (*str == '%')
		{
			offset = ft_parser(++str, &codes);
			count += ft_print_anything(ap, &codes);
			str += offset;
		}
		else
		{
			ft_putchar(*str++);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
