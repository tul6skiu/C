/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:36:18 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:40:18 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		count_int(t_int *integer)
{
	int n;

	n = 0;
	while (integer)
	{
		n++;
		integer = integer->next;
	}
	return (n);
}
