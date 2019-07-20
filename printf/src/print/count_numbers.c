/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:31:34 by vrestles          #+#    #+#             */
/*   Updated: 2019/01/10 13:31:37 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_sign_numbers(long long int n)
{
	int	count;

	count = 1;
	if (n == -9223372036854775807 - 1)
		return (19);
	if (n < 0)
		n = n * (-1);
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int		ft_count_unsign_numbers(unsigned long long int n)
{
	int		count;

	count = 1;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int		get_len(long long int n, t_codes *codes)
{
	int		len;

	len = 0;
	if (n == 0 && !codes->sign)
		return (1);
	if (codes->sign)
	{
		len += 2;
		n /= 10;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
