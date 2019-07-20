/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modificators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:52:30 by vrestles          #+#    #+#             */
/*   Updated: 2019/01/10 13:54:40 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_is_flag(char c)
{
	if (c == '-')
		return (1);
	if (c == '+')
		return (2);
	if (c == '0')
		return (3);
	if (c == ' ')
		return (4);
	if (c == '#')
		return (5);
	if (c == '$' || c == '*' || c == '\'')
		return (6);
	return (0);
}

int			ft_is_size(char *str)
{
	if (str[0] == 'h' && str[1] == 'h')
		return (1);
	else if (str[0] == 'h' && str[1] != 'h')
		return (2);
	else if (str[0] == 'l' && str[1] != 'l')
		return (3);
	else if (str[0] == 'l' && str[1] == 'l')
		return (4);
	else if (str[0] == 'L')
		return (5);
	else if (str[0] == 'j' || str[0] == 'z')
		return (6);
	return (0);
}

int			ft_is_prec(char *str, t_codes *codes)
{
	int count;
	int num;

	count = 0;
	codes->prec = -1;
	while (*str == '0')
	{
		str++;
		count++;
	}
	num = ft_atoi(str);
	if (num != 0)
	{
		codes->prec = num;
		count += ft_count_sign_numbers(num);
	}
	return (count);
}

int			ft_find_flag(t_codes *codes, int n)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if (codes->flags[i] == n)
			return (1);
		i++;
	}
	return (0);
}
