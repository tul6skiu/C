/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:39:40 by gkoch             #+#    #+#             */
/*   Updated: 2019/01/07 13:40:07 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_atoi_double(const char *str)
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
	return ((double)an);
}
