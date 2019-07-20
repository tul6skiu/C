/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:29:33 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 21:27:05 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void		get_coordinates(t_lem **lem, t_graf **graf, char **line)
{
	char	**param;
	t_kin	*room;

	if (!line)
		eeerrror();
	else if (check_char(*line, ' '))
		get_comment(lem, graf, line);
	else if (check_char(*line, '-'))
		get_connect(lem, graf, line);
}

static void		set_startend(t_graf **graf)
{
	t_rooms		*room;

	push_rooms(&(*graf)->rooms, create_rooms(ft_strdup((*graf)->start)));
	room = create_rooms(ft_strdup((*graf)->end));
	unshift_rooms(&(*graf)->rooms, &room);
}

void			get_data(t_lem **lem, t_graf **graf, t_char **book)
{
	char	*line;

	line = NULL;
	while (gnl(0, &line))
	{
		push_char(book, str_to_char(line));
		push_char(book, create_char('\n'));
		if (check_tag(lem, graf, &line, book))
		{
			continue ;
		}
		get_coordinates(lem, graf, &line);
	}
	if (!(*graf)->start || !(*graf)->end
		|| !(*graf)->kin || !(*graf)->rooms)
		eeerrror();
	set_startend(graf);
}
