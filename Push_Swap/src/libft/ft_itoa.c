/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:06:34 by wlister           #+#    #+#             */
/*   Updated: 2018/11/23 16:06:36 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int		len(long nb)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static void		ft_res(char *str, long i, long n)
{
	while (n > 0)
	{
		*(str + i) = 48 + (n % 10);
		n = n / 10;
		--i;
	}
}

char			*ft_itoa(int nb)
{
	char	*str;
	long	n;
	long	i;

	n = nb;
	i = len(n);
	if (i == 0)
		i = i + 1;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	ft_res(str, i, n);
	return (str);
}
