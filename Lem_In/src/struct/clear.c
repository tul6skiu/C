/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:08:39 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:42:00 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void		clear_kin(t_kin **kin)
{
	t_kin	*next;

	while (*kin)
	{
		next = (*kin)->next;
		free((*kin)->name[0]);
		(*kin)->name[0] = NULL;
		free((*kin)->name[1]);
		(*kin)->name[1] = NULL;
		free((*kin)->name);
		(*kin)->name = NULL;
		(*kin)->next = NULL;
		free(*kin);
		*kin = next;
	}
}

static void		clear_rooms(t_rooms **rooms)
{
	t_rooms		*next;

	while (*rooms)
	{
		next = (*rooms)->next;
		free((*rooms)->name);
		(*rooms)->name = NULL;
		(*rooms)->next = NULL;
		free(*rooms);
		*rooms = next;
	}
}

void			clear_groups(t_groups **groups)
{
	t_groups	*next;

	while (*groups)
	{
		next = (*groups)->next;
		(void)(*groups)->count;
		(*groups)->stream = NULL;
		free(*groups);
		(*groups) = next;
	}
}

void			clear_ants(t_ants **ants)
{
	t_ants		*next;

	while (*ants)
	{
		next = (*ants)->next;
		(void)(*ants)->name;
		(void)(*ants)->rooms;
		(*ants)->stream = NULL;
		free(*ants);
		(*ants) = next;
	}
}

void			clear_graf(t_graf **graf)
{
	free((*graf)->start);
	(*graf)->start = NULL;
	free((*graf)->end);
	(*graf)->end = NULL;
	clear_kin(&(*graf)->kin);
	clear_rooms(&(*graf)->rooms);
	free(*graf);
	*graf = NULL;
}
