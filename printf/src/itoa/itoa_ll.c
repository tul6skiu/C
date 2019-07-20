/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_ll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:41:11 by vrestles          #+#    #+#             */
/*   Updated: 2019/01/10 13:50:13 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*positive_num_into_char(long long int nb)
{
	int		i;
	char	*res;

	i = ft_count_sign_numbers(nb);
	res = (char *)malloc(sizeof(char) * (i + 1));
	CHECK(res);
	res[i--] = '\0';
	while (i >= 0)
	{
		res[i] = ((nb % 10) + '0');
		nb = nb / 10;
		i--;
	}
	return (res);
}

static char		*min_negative_num_into_char(void)
{
	int				i;
	char			*res;
	long long int	new;

	new = 922337203685477580;
	i = ft_count_sign_numbers(new) + 2;
	res = (char *)malloc(sizeof(char) * (i + 1));
	CHECK(res);
	res[i--] = '\0';
	res[i--] = '8';
	while (i > 0)
	{
		res[i] = ((new % 10) + '0');
		new = new / 10;
		i--;
	}
	res[i] = '-';
	return (res);
}

static char		*negative_num_into_char(long long int nb)
{
	int		i;
	char	*res;

	if (nb == -9223372036854775807 - 1)
		return (min_negative_num_into_char());
	nb = (-1) * nb;
	i = ft_count_sign_numbers(nb) + 1;
	res = (char *)malloc(sizeof(char) * (i + 1));
	CHECK(res);
	res[i--] = '\0';
	while (i > 0)
	{
		res[i] = ((nb % 10) + '0');
		nb = nb / 10;
		i--;
	}
	res[i] = '-';
	return (res);
}

char			*ft_ll_itoa(long long int nb)
{
	char	*res;

	if (nb < 0)
		res = negative_num_into_char(nb);
	else
		res = positive_num_into_char(nb);
	return (res);
}
