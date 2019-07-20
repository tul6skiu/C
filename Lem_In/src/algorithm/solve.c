/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:59:20 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 21:14:43 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static int		check_steam(t_lem *lem, t_stream *stream, int check)
{
	if (check == lem->rooms - 1)
		return (1);
	while (stream)
	{
		if (stream->used[check])
			return (0);
		stream = stream->next;
	}
	return (1);
}

static int		check_valid(int *mas, int stop)
{
	int n;

	n = 0;
	if (!mas[n])
		return (1);
	while (n != stop)
	{
		if (!mas[n])
			return (n);
		n = mas[n];
	}
	return (0);
}

static void		clear_id_rooms(t_lem *lem)
{
	int		n;

	n = 0;
	while (n < lem->rooms)
	{
		lem->row[n].id = 2147483647;
		n++;
	}
}

static int		len_stream(int *mas, int stop)
{
	int n;
	int len;

	n = 0;
	len = 0;
	while (n != stop)
	{
		len++;
		if (!mas[n])
			return (n);
		n = mas[n];
	}
	return (len);
}

void			solve(t_lem *lem, t_stream **streams)
{
	t_stream	*stream;

	*streams = NULL;
	while (1)
	{
		part1(lem);
		stream = create_stream(create_mas(lem->rooms), create_int(0));
		part2(lem, stream);
		if (check_valid(stream->used, lem->rooms - 1))
		{
			clear_streams(&stream);
			return ;
		}
		stream->len = len_stream(stream->used, lem->rooms - 1);
		push_stream(streams, stream);
		del_connecting(lem, stream->used);
		clear_id_rooms(lem);
	}
}
