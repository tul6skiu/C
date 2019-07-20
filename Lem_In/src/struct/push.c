/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:28:33 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:20:01 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		push_rooms(t_rooms **begin_list, t_rooms *data)
{
	t_rooms	*next;

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

int		push_stream(t_stream **begin_list, t_stream *data)
{
	t_stream	*next;

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
