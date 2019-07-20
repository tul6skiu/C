/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:31:57 by vrestles          #+#    #+#             */
/*   Updated: 2019/01/10 13:32:00 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int			ft_get_sign_number(va_list ap, t_codes *codes)
{
	if (codes->size == 4 || codes->size == 6)
		return (va_arg(ap, long long int));
	else if (codes->size == 3)
		return (va_arg(ap, long int));
	else
		return (va_arg(ap, int));
}

unsigned long long int	ft_get_unsign_number(va_list ap, t_codes *codes)
{
	if (codes->size == 4 || codes->size == 6)
		return (va_arg(ap, unsigned long long int));
	else if (codes->size == 3)
		return (va_arg(ap, unsigned long int));
	else
		return (va_arg(ap, unsigned int));
}

long long int			ft_sign_size_applicate(long long int nb, t_codes *codes)
{
	long long int new;

	if (codes->size == 1)
		new = (signed char)nb;
	else if (codes->size == 2)
		new = (short)nb;
	else
		new = nb;
	return (new);
}

unsigned long long int	ft_un_si_app(unsigned long long int nb, t_codes *codes)
{
	unsigned long long int new;

	if (codes->size == 1)
		new = (unsigned char)nb;
	else if (codes->size == 2)
		new = (unsigned short)nb;
	else
		new = nb;
	return (new);
}

long double				ft_get_any_double(va_list ap, t_codes *codes)
{
	if (codes->size == 5)
		return (va_arg(ap, long double));
	else
		return (va_arg(ap, double));
}
