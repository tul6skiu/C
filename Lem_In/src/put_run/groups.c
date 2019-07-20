/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:20:28 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 21:20:50 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static t_stream		*get_min_stream(t_stream *streams)
{
	t_stream		*stream;
	int				n;

	stream = streams;
	n = stream->len;
	streams = streams->next;
	while (streams)
	{
		if (n > streams->len)
		{
			stream = streams;
			n = stream->len;
		}
		streams = streams->next;
	}
	return (stream);
}

static int			check_stream_group(t_groups *groups, t_stream *stream)
{
	while (groups)
	{
		if (groups->stream == stream)
		{
			groups->count++;
			return (0);
		}
		groups = groups->next;
	}
	return (1);
}

void				set_groups(t_lem *lem, t_stream *streams, t_groups **groups)
{
	t_stream	*stream;

	while (lem->ants)
	{
		stream = get_min_stream(streams);
		if (check_stream_group(*groups, stream))
			unshift_groups(groups, create_group(stream));
		stream->len++;
		lem->ants--;
	}
}
