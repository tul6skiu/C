/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:39:51 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 20:26:17 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		get_ants(t_lem **lem, t_char **book)
{
	int		n;
	char	*line;

	line = NULL;
	gnl(0, &line);
	n = 0;
	if (!line)
		eeerrror();
	*book = str_to_char(line);
	push_char(book, create_char('\n'));
	while (line[n])
	{
		if (!(line[n] >= '0' && line[n] <= '9'))
			eeerrror();
		n++;
	}
	(*lem)->ants = ft_atoi(line);
	if ((*lem)->ants < 1)
		eeerrror();
	free(line);
}
