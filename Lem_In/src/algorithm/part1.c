/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:08:18 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 21:08:34 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void		part1_bfs(t_lem *lem, t_int **turn)
{
	int		item;
	t_int	*line;

	item = shift_int(turn);
	line = lem->row[item].line;
	while (line)
	{
		if (lem->row[line->integer].id == 2147483647 && \
			line->integer && line->integer != lem->rooms - 1)
		{
			if (lem->row[line->integer].id > lem->row[item].id + 1
				|| lem->row[line->integer].id == 2147483647)
				lem->row[line->integer].id = lem->row[item].id + 1;
			push_int(turn, create_int(line->integer));
		}
		line = line->next;
	}
}

void			part1(t_lem *lem)
{
	t_int	*turn;

	turn = create_int(lem->rooms - 1);
	lem->row[lem->rooms - 1].id = 0;
	while (turn)
	{
		part1_bfs(lem, &turn);
	}
}
