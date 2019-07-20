/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tetr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:05:23 by afalmer-          #+#    #+#             */
/*   Updated: 2018/12/10 17:05:24 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_cut_lines(char **tetr, int *start, int *end)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	flag = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetr[i][j++] != '.')
			{
				if (flag == 0)
				{
					*start = i;
					*end = i;
					flag = 1;
					break ;
				}
				*end = i;
			}
		}
		i++;
	}
}

void	ft_cut_col(char **tetr, int *start, int *end)
{
	int		i;
	int		j;
	int		flag;

	j = -1;
	i = 0;
	flag = 0;
	while (++j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetr[i++][j] != '.')
			{
				if (flag == 0)
				{
					*start = j;
					*end = j;
					flag = 1;
					break ;
				}
				*end = j;
			}
		}
	}
}

char	**ft_set_tetr(char **tetr, t_coord coord)
{
	char	**result;
	char	**temp;
	int		i;

	if (!(result = (char**)malloc(sizeof(char*) * \
				(coord.end_i - coord.start_i + 2))))
		return (0);
	*(result + (coord.end_i - coord.start_i + 1)) = NULL;
	temp = result;
	i = coord.start_i;
	while (i <= coord.end_i)
	{
		*temp++ = ft_strsub(*(tetr + i), coord.start_j, \
						coord.end_j - coord.start_j + 1);
		i++;
	}
	return (result);
}

char	**ft_cut_tetr(char **tetr)
{
	char	**result;
	t_coord	coord;

	coord.start_i = 0;
	coord.end_i = 3;
	coord.start_j = 0;
	coord.end_j = 3;
	ft_cut_lines(tetr, &coord.start_i, &coord.end_i);
	ft_cut_col(tetr, &coord.start_j, &coord.end_j);
	result = ft_set_tetr(tetr, coord);
	return (result);
}
