/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 03:33:20 by gkoch             #+#    #+#             */
/*   Updated: 2018/11/22 17:36:12 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putchar(char c)
{
	unsigned char	tmp;
	unsigned char	ch;

	ch = (unsigned char)c;
	if (ch > 127)
	{
		tmp = (ch >> 6) | 0b11000000;
		write(1, &tmp, 1);
		tmp = ch & 0b10111111;
		write(1, &tmp, 1);
	}
	else
		write(1, &c, 1);
}
