/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unshift_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:00:07 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 20:00:12 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		unshift_char(t_char **begin_list, t_char *data)
{
	t_char	*next;

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
