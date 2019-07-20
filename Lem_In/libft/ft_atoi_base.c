/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:40:03 by gkoch             #+#    #+#             */
/*   Updated: 2018/12/19 17:48:41 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_compare_base(char c, char *base)
{
	int		n;

	n = -1;
	while (base[++n])
		if (base[n] == c)
			return (n);
	return (-1);
}

static int	ft_checkstr(char *str)
{
	int		n;
	int		flag;

	n = -1;
	flag = 0;
	while (str[++n])
		if ((str[n] == '-') || (str[n] == '+'))
			flag = -1;
	return (n + flag);
}

int			ft_atoi_base(char *str, char *base)
{
	int		n;
	int		flag;
	int		sum;
	int		power;

	n = 0;
	flag = 1;
	sum = 0;
	if (!(power = ft_checkstr(str)))
		return (0);
	while (str[n] == 32 || (str[n] >= 9 && str[n] <= 13))
		n++;
	if (str[n] == '-')
		flag = -1;
	if ((str[n] == '-') || (str[n] == '+'))
		n++;
	while (ft_compare_base(str[n], base) != -1)
	{
		sum += ft_compare_base(str[n], base) * (int)ft_power(ft_checkstr(base),
			--power);
		n++;
	}
	return (sum * flag);
}
