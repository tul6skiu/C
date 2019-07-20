/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unshift.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:32:40 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:20:17 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		unshift_kin(t_kin **begin_list, t_kin **data)
{
	t_kin	*next;

	if (!*data)
		return (1);
	next = *begin_list;
	if (next)
	{
		(*data)->next = *begin_list;
		*begin_list = *data;
	}
	else
		*begin_list = *data;
	return (0);
}

int		unshift_rooms(t_rooms **begin_list, t_rooms **data)
{
	t_rooms	*next;

	if (!*data)
		return (1);
	next = *begin_list;
	if (next)
	{
		(*data)->next = *begin_list;
		*begin_list = *data;
	}
	else
		*begin_list = *data;
	return (0);
}

int		unshift_stream(t_stream **begin_list, t_stream *data)
{
	t_stream	*next;

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

int		unshift_ant(t_ants **begin_list, t_ants *data)
{
	t_ants	*next;

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

int		unshift_groups(t_groups **begin_list, t_groups *data)
{
	t_groups	*next;

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
