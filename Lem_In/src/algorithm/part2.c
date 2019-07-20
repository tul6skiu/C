/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:09:04 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 21:09:17 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static int		get_mini_id(t_lem *lem, t_int *line, t_stream *stream)
{
	int		id;
	int		room;

	id = 2147483647;
	room = -3;
	while (line)
	{
		if (!stream->used[line->integer] && id > lem->row[line->integer].id)
		{
			id = lem->row[line->integer].id;
			room = line->integer;
		}
		line = line->next;
	}
	return (room);
}

void			part2(t_lem *lem, t_stream *stream)
{
	int		room;
	int		turn;

	if (stream->turn)
	{
		turn = shift_int(&stream->turn);
		room = get_mini_id(lem, lem->row[turn].line, stream);
		if (room == -3 || turn >= lem->rooms)
			return ;
		if (lem->row[turn].id > lem->row[room].id && (!stream->used[room]
													|| room == lem->rooms - 1))
		{
			stream->used[turn] = room;
			if (room != lem->rooms - 1)
				push_int(&stream->turn, create_int(room));
			if (room != lem->rooms - 1)
				part2(lem, stream);
		}
	}
}
