/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:54:39 by wlister           #+#    #+#             */
/*   Updated: 2018/12/01 11:54:44 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/libft.h"

static int		step_of_line(char *result)
{
	int		step;

	step = 0;
	while (result[step] != '\n' && result[step])
		step++;
	if (result[step] == '\n')
	{
		result[step] = '\n';
	}
	return (step);
}

static int		end_of_line(char **result, char **line)
{
	int		count;
	char	*tmp;

	count = step_of_line(*result);
	if ((*result)[count] == '\n')
	{
		*line = ft_strsub(*result, 0, count);
		tmp = ft_strsub(*result, count + 1, ft_strlen(*result));
		free(*result);
		*result = tmp;
		return (1);
	}
	else if (ft_strlen(*result) > 0)
	{
		*line = ft_strdup(*result);
		*result = 0;
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*result[MAX_FD];
	char			buffer[BUFF_SIZE + 1];
	char			*tmp_res;
	int				size;

	if (fd < 0 || fd > MAX_FD || line == NULL)
		return (-1);
	if (!result[fd] && !(result[fd] = ft_strnew(1)))
		return (-1);
	while ((size = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[size] = '\0';
		tmp_res = ft_strjoin(result[fd], buffer);
		free(result[fd]);
		result[fd] = tmp_res;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (size == -1)
		return (-1);
	return (end_of_line(&(result[fd]), line));
}
