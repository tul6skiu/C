/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:58:28 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:58:49 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		push_char(t_char **begin_list, t_char *data)
{
	t_char	*next;

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
