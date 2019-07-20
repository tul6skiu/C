/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:46:48 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 18:05:06 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static int		check_rooms(t_rooms *rooms, char *name)
{
	while (rooms)
	{
		if (!ft_strcmp(rooms->name, name))
			return (0);
		rooms = rooms->next;
	}
	return (1);
}

static int		check_intager(char *str)
{
	int		n;

	n = 0;
	while (str[n])
	{
		if (!(str[n] >= '0' && str[n] <= '9'))
			return (0);
		n++;
	}
	return (1);
}

void			get_comment(t_lem **lem, t_graf **graf, char **line)
{
	char	**param;
	t_rooms	*room;

	param = ft_strsplit(*line, ' ');
	if (count_arr_ch(param) != 3 || !check_intager(param[1])
	|| !check_intager(param[2]))
		eeerrror();
	if (check_rooms((*graf)->rooms, param[0]))
	{
		room = create_rooms(ft_strdup(param[0]));
		unshift_rooms(&(*graf)->rooms, &room);
	}
	(*lem)->rooms += 1;
	clear_arr_ch(&param);
	free(*line);
	line = NULL;
}

static int		check_kin(t_graf **graf, char ***name)
{
	t_kin		*next;

	next = (*graf)->kin;
	while (next)
	{
		if (!ft_strcmp(next->name[0], (*name)[0]))
			return (0);
		next = next->next;
	}
	return (1);
}

void			get_connect(t_lem **lem, t_graf **graf, char **line)
{
	char	**param;
	t_kin	*kin;

	param = ft_strsplit(*line, '-');
	if (count_arr_ch(param) != 2)
		eeerrror();
	kin = create_kin(param);
	unshift_kin(&(*graf)->kin, &kin);
	free(*line);
	line = NULL;
}
