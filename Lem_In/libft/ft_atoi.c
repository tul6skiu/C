/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 03:00:21 by gkoch             #+#    #+#             */
/*   Updated: 2018/12/19 11:19:07 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	long long	flag;
	long long	an;

	flag = 1;
	an = 0;
	while (*str == 32 || ((*str >= 0) && (*str <= 13)))
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '-' || (*str == '+'))
		str++;
	while (*str == '0')
		str++;
	while (*str && (*str >= '0') && (*str <= '9'))
	{
		if (an < 0 && ((an * 10 + 48 - *str) < 0))
			an = (an * 10 + 48 - *str++);
		else if (an >= 0 && ((an * 10 - 48 + *str) >= 0))
			an = (an * 10 - 48 + *str++) * flag;
		else
			return (-1 * flag * (an > 0));
		flag = 1;
	}
	return ((int)an);
}
