/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tetr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:09:16 by afalmer-          #+#    #+#             */
/*   Updated: 2018/12/10 17:09:16 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_line(char *str, int count_lines, int *count_sharp)
{
	int		count_c;

	count_c = 0;
	while (*str)
	{
		if (*str != '.' && *str != '#' && *str != '\n')
			return (0);
		if (*str == '#')
		{
			*str = 'A' + count_lines / 5;
			(*count_sharp)++;
		}
		str++;
		count_c++;
	}
	if (count_c != 4)
		return (0);
	return (1);
}

void	ft_free_multiarr(char **tetr)
{
	while (*tetr)
	{
		ft_strdel(tetr++);
	}
}

int		ft_tetr_to_list(t_figures **figures, char **tetr, \
						int *count_sharp, int count_lines)
{
	if (*count_sharp != 4 || count_lines % 5 != 0)
		return (0);
	if (!ft_create_figures(figures, ft_cut_tetr(tetr)))
		return (0);
	ft_free_multiarr(tetr);
	*count_sharp = 0;
	return (1);
}

int		ft_read_tetr(int fd, t_figures **figures)
{
	char		**tetr;
	char		*line;
	t_counts	counts;
	int			gnl;

	if (!(tetr = (char**)malloc(sizeof(char*) * 5)))
		return (0);
	*(tetr + 4) = NULL;
	counts.lines = 0;
	counts.sharp = 0;
	while ((gnl = get_next_line(fd, &line)) >= 0 && ++counts.lines)
	{
		if (!gnl || !*line)
		{
			if (!ft_tetr_to_list(figures, tetr, &counts.sharp, counts.lines))
				return (0);
			if (gnl == 0)
				break ;
		}
		else if (!ft_check_line(line, counts.lines, &counts.sharp))
			return (0);
		else if (counts.lines % 5 != 0)
			tetr[counts.lines % 5 - 1] = line;
	}
	return (counts.lines / 5);
}
