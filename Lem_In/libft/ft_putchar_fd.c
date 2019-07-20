/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 03:29:18 by gkoch             #+#    #+#             */
/*   Updated: 2018/11/22 17:36:02 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	tmp;
	unsigned char	ch;

	ch = (unsigned char)c;
	if (ch > 127)
	{
		tmp = (ch >> 6) | 0b11000000;
		write(fd, &tmp, 1);
		tmp = ch & 0b10111111;
		write(fd, &tmp, 1);
	}
	else
		write(fd, &c, 1);
}
