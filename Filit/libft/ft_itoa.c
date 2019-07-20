/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:36:37 by afalmer-          #+#    #+#             */
/*   Updated: 2018/11/27 17:36:39 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int		len;

	len = 0;
	while (n /= 10)
		len++;
	return (len + 1);
}

char		*ft_itoa(int n)
{
	char			*res;
	char			*new_res;
	int				sign;
	int				len;
	unsigned int	num;

	num = n < 0 ? -n : n;
	sign = n < 0 ? 1 : 0;
	len = ft_numlen(num);
	if ((res = ft_strnew(len + sign)) == NULL)
		return (NULL);
	new_res = res + len + sign - 1;
	while (len--)
	{
		*new_res-- = num % 10 + '0';
		num /= 10;
	}
	if (sign)
		*new_res = '-';
	return (res);
}
