/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:52:45 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 10:48:57 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static int		check_position(t_rooms *rooms, char *str, int n)
{
	while (rooms)
	{
		n--;
		if (!ft_strcmp(str, rooms->name))
			return (n);
		rooms = rooms->next;
	}
	eeerrror();
	return (0);
}

static void		set_list(t_lem *lem, t_graf *graf)
{
	t_kin	*kin;
	int		x;
	int		y;

	kin = graf->kin;
	while (kin)
	{
		x = check_position(graf->rooms, (kin->name)[0], lem->rooms);
		y = check_position(graf->rooms, (kin->name)[1], lem->rooms);
		unshift_int(&((lem->row)[x].line), create_int(y));
		unshift_int(&((lem->row)[y].line), create_int(x));
		lem->row[x].name = (kin->name)[0];
		lem->row[y].name = (kin->name)[1];
		kin = kin->next;
	}
}

t_row			*create_row(int len)
{
	int		n;
	t_row	*row;

	n = 0;
	row = (t_row *)ft_memalloc(sizeof(t_row) * len);
	while (n < len)
	{
		row[n].line = NULL;
		row[n].id = 2147483647;
		n++;
	}
	return (row);
}

void			get_list(t_lem **lem, t_graf *graf)
{
	(*lem)->row = create_row((*lem)->rooms);
	set_list(*lem, graf);
}
