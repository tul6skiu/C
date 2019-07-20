/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:03:29 by gkoch             #+#    #+#             */
/*   Updated: 2019/02/23 15:47:45 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_line(char **line, char **turn)
{
	char	*item;

	if ((item = ft_strchr(*turn, '\n')))
	{
		item[0] = '\0';
		*line = ft_strdup(*turn);
		item = ft_strdup(&item[1]);
		free(*turn);
		*turn = item;
		return (1);
	}
	*line = ft_strdup(*turn);
	free(*turn);
	*turn = NULL;
	return (1);
}

int			gnl(const int fd, char **line)
{
	int				n;
	char			buf[5 + 1];
	static char		*turn[259];
	char			*item;

	if (fd < 0 || !line)
		return (-1);
	if (turn[fd] == NULL)
		turn[fd] = ft_strdup("\0");
	while (!ft_strchr(turn[fd], '\n') && (n = read(fd, buf, 5)) && (n != 0))
	{
		if (n < 0)
			return (-1);
		buf[n] = '\0';
		if (!turn[fd])
			item = buf;
		else
			item = ft_strjoin(turn[fd], buf);
		free(turn[fd]);
		turn[fd] = item;
	}
	if (turn[fd][0] == '\0' && !n)
		return (0);
	return (ft_set_line(line, &turn[fd]));
}
