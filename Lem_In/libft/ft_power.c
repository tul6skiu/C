/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:04:28 by gkoch             #+#    #+#             */
/*   Updated: 2018/12/19 17:04:41 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_power(double nb, int power)
{
	if (power <= -1)
		return (0);
	if (power > 1)
		nb *= ft_power(nb, power - 1);
	if (power == 0 || ((nb < 0) && (power == 0)))
		return (1);
	return (nb);
}
