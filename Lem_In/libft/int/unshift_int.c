/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unshift_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:39:47 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:39:56 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		unshift_int(t_int **begin_list, t_int *data)
{
	t_int	*next;

	if (!data)
		return (1);
	next = *begin_list;
	if (next)
	{
		data->next = *begin_list;
		*begin_list = data;
	}
	else
		*begin_list = data;
	return (0);
}
