/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_connecting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:11:23 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 21:11:54 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static t_int	*del_connect(t_int *line, int y)
{
	t_int	**old;
	t_int	*item;

	old = &line;
	while ((*old)->next)
	{
		if ((*old)->next->integer == y)
		{
			item = (*old)->next->next;
			free((*old)->next);
			(*old)->next = item;
			return (line);
		}
		old = &(*old)->next;
	}
	return (line);
}

static void		del_connects(t_lem *lem, int x, int y)
{
	lem->row[x].line = del_connect(lem->row[x].line, y);
	lem->row[y].line = del_connect(lem->row[y].line, x);
}

void			del_connecting(t_lem *lem, int *used)
{
	int		n;
	int		item;
	t_int	*line;

	n = 0;
	while (n != lem->rooms - 1)
	{
		if (used[n] != 0 && (used[n] != (lem->rooms - 1)))
		{
			line = lem->row[used[n]].line;
			while (line)
			{
				item = line->integer;
				line = line->next;
				del_connects(lem, used[n], item);
			}
		}
		n = used[n];
		if (!n)
			return ;
	}
}
