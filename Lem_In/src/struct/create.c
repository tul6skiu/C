/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:00:52 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:20:16 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_kin		*create_kin(char **name)
{
	t_kin	*new;

	if (!(new = (t_kin*)ft_memalloc(sizeof(t_kin))))
		exit(EXIT_FAILURE);
	new->name = name;
	new->next = NULL;
	return (new);
}

t_rooms		*create_rooms(char *name)
{
	t_rooms	*new;

	if (!(new = (t_rooms*)ft_memalloc(sizeof(t_rooms))))
		exit(EXIT_FAILURE);
	new->name = name;
	new->next = NULL;
	return (new);
}

t_stream	*create_stream(int *used, t_int *turn)
{
	t_stream	*new;

	if (!(new = (t_stream*)ft_memalloc(sizeof(t_stream))))
		exit(EXIT_FAILURE);
	new->len = 0;
	new->used = used;
	new->turn = turn;
	new->next = NULL;
	return (new);
}

t_ants		*create_ant(int name, t_stream *stream)
{
	t_ants	*new;

	if (!(new = (t_ants*)ft_memalloc(sizeof(t_ants))))
		exit(EXIT_FAILURE);
	new->name = name;
	new->rooms = 0;
	new->stream = stream;
	new->next = NULL;
	return (new);
}

t_groups	*create_group(t_stream *stream)
{
	t_groups	*new;

	if (!(new = (t_groups*)ft_memalloc(sizeof(t_groups))))
		exit(EXIT_FAILURE);
	new->count = 1;
	new->stream = stream;
	new->next = NULL;
	return (new);
}
