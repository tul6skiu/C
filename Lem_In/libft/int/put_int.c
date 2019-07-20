/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:38:40 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:38:56 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	put_int(t_int *integer)
{
	while (integer)
	{
		ft_putnbr(integer->integer);
		if (integer->next)
			ft_putstr(" ");
		integer = integer->next;
	}
}
