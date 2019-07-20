/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:53:08 by wlister           #+#    #+#             */
/*   Updated: 2019/04/06 21:53:10 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_lem		*create_lem(void)
{
	t_lem	*new;

	if (!(new = (t_lem*)ft_memalloc(sizeof(t_lem))))
		exit(EXIT_FAILURE);
	new->ants = 0;
	new->rooms = 2;
	new->row = NULL;
	new->graf = NULL;
	return (new);
}

t_graf		*create_graf(void)
{
	t_graf	*new;

	if (!(new = (t_graf*)ft_memalloc(sizeof(t_graf))))
		exit(EXIT_FAILURE);
	new->start = NULL;
	new->end = NULL;
	new->kin = NULL;
	new->rooms = NULL;
	return (new);
}

void		clear_streams(t_stream **streams)
{
	t_stream	*next;

	while (*streams)
	{
		next = (*streams)->next;
		(void)(*streams)->len;
		free((*streams)->used);
		free(*streams);
		(*streams) = next;
	}
}

void		clear_row(t_row **row, int rooms)
{
	int		n;

	n = 0;
	while (n < rooms)
	{
		(void)(*row)[n].id;
		(*row)[n].name = NULL;
		if ((*row)[n].line)
			clear_int(&(*row)[n].line);
		n++;
	}
	free(*row);
	*row = NULL;
}

void		clear_lem(t_lem **lem)
{
	clear_row(&(*lem)->row, (*lem)->rooms);
	clear_graf(&(*lem)->graf);
	(void)(*lem)->ants;
	(void)(*lem)->rooms;
	free(*lem);
	*lem = NULL;
}
