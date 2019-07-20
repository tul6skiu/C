/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:42:35 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 21:24:09 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void		get_start(t_lem **lem, t_graf **graf, t_char **book)
{
	char	*line;
	char	**param;

	line = NULL;
	gnl(0, &line);
	push_char(book, str_to_char(line));
	push_char(book, create_char('\n'));
	param = ft_strsplit(line, ' ');
	if (count_arr_ch(param) != 3)
		eeerrror();
	(*graf)->start = ft_strdup(param[0]);
	free(line);
	line = NULL;
	clear_arr_ch(&param);
}

static void		get_end(t_lem **lem, t_graf **graf, t_char **book)
{
	char	*line;
	char	**param;

	line = NULL;
	gnl(0, &line);
	push_char(book, str_to_char(line));
	push_char(book, create_char('\n'));
	param = ft_strsplit(line, ' ');
	if (count_arr_ch(param) != 3)
		eeerrror();
	(*graf)->end = ft_strdup(param[0]);
	free(line);
	line = NULL;
	clear_arr_ch(&param);
}

static int		check_lines(t_lem **lem, t_graf **graf, char **str)
{
	char	**param;
	int		answer;

	if (!str)
		eeerrror();
	param = ft_strsplit(*str, ':');
	if (count_arr_ch(param) != 2)
		answer = 0;
	else if (!ft_strcmp(param[0], "#Here is the number of lines required"))
	{
		free(*str);
		answer = 1;
	}
	else
		answer = 0;
	clear_arr_ch(&param);
	return (answer);
}

int				check_tag(t_lem **lem, t_graf **graf, char **line,
						t_char **book)
{
	if (!ft_strcmp(*line, "#comment") || !ft_strcmp(*line, "#another comment"))
	{
		free(*line);
		return (1);
	}
	else if (!ft_strcmp(*line, "##start"))
	{
		if ((*graf)->start)
			eeerrror();
		free(*line);
		line = NULL;
		get_start(lem, graf, book);
		return (1);
	}
	else if (!ft_strcmp(*line, "##end"))
	{
		if ((*graf)->end)
			eeerrror();
		free(*line);
		line = NULL;
		get_end(lem, graf, book);
		return (1);
	}
	else
		return (check_lines(lem, graf, line));
}
