/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:38:10 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:38:29 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		push_int(t_int **begin_list, t_int *data)
{
	t_int	*next;

	if (!data)
		return (1);
	next = *begin_list;
	if (next)
	{
		while (next->next)
			next = next->next;
		next->next = data;
	}
	else
		*begin_list = data;
	return (0);
}
