/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lim_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:19:12 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 20:19:42 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		check_repeat_rooms(t_rooms *rooms)
{
	t_rooms		*room;

	while (rooms)
	{
		room = rooms->next;
		while (room)
		{
			if (!ft_strcmp(room->name, rooms->name))
				eeerrror();
			room = room->next;
		}
		rooms = rooms->next;
	}
}

void		lim_read(t_lem **lem, t_char **book)
{
	t_graf	*graf;

	*book = NULL;
	graf = create_graf();
	*lem = create_lem();
	get_ants(lem, book);
	get_data(lem, &graf, book);
	check_repeat_rooms(graf->rooms);
	get_list(lem, graf);
	(*lem)->graf = graf;
}
