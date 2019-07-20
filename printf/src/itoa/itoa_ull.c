/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_ull.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:50:30 by vrestles          #+#    #+#             */
/*   Updated: 2019/01/10 13:51:50 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*positive_num_into_char(unsigned long long int nb)
{
	int		i;
	char	*res;

	i = ft_count_unsign_numbers(nb);
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

char			*ft_ull_itoa(unsigned long long int nb)
{
	char	*res;

	res = positive_num_into_char(nb);
	return (res);
}
