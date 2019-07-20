/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coincidence_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:35:55 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:36:10 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_int	*coincidence_int(t_int *integer, int coincidence)
{
	while (integer)
	{
		if (integer->integer == coincidence)
			return (integer);
		integer = integer->next;
	}
	return (NULL);
}
