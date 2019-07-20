/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:41:42 by afalmer-          #+#    #+#             */
/*   Updated: 2018/12/13 17:41:45 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(t_figures *figures, t_res res, int x, int y)
{
	char	*temp_tetr;
	char	*temp_map;
	char	**tetr;
	char	**map;

	map = res.map;
	tetr = figures->tetrimino;
	while (*tetr)
	{
		temp_tetr = *tetr;
		temp_map = *(map + y);
		while (*temp_tetr)
		{
			if (*temp_tetr != '.' && *(temp_map + x) != '.')
				return (0);
			temp_tetr++;
			temp_map++;
		}
		tetr++;
		map++;
	}
	return (1);
}

void	ft_set(t_figures *figures, t_res res, int x, int y)
{
	char	*temp_tetr;
	char	*temp_map;
	char	**tetr;
	char	**map;

	map = res.map;
	tetr = figures->tetrimino;
	while (*tetr)
	{
		temp_tetr = *tetr;
		temp_map = *(map + y);
		while (*temp_tetr)
		{
			if (*temp_tetr != '.')
				*(temp_map + x) = *temp_tetr;
			temp_tetr++;
			temp_map++;
		}
		tetr++;
		map++;
	}
}

void	ft_reset(t_figures *figures, t_res res, int x, int y)
{
	char	*temp_tetr;
	char	*temp_map;
	char	**tetr;
	char	**map;

	map = res.map;
	tetr = figures->tetrimino;
	while (*tetr)
	{
		temp_tetr = *tetr;
		temp_map = *(map + y);
		while (*temp_tetr)
		{
			if (*temp_tetr != '.')
				*(temp_map + x) = '.';
			temp_tetr++;
			temp_map++;
		}
		tetr++;
		map++;
	}
}

int		ft_try(t_figures *figures, t_res res, int x, int y)
{
	int		result;

	result = 0;
	if (ft_check(figures, res, x, y))
	{
		ft_set(figures, res, x, y);
		if (figures->next == NULL)
			result = 1;
		else if (!(result = ft_try(figures->next, res, 0, 0)))
			ft_reset(figures, res, x, y);
	}
	if (result)
		return (result);
	else if (figures->length + x + 1 <= res.board)
		result = ft_try(figures, res, x + 1, y);
	else if (figures->height + y + 1 <= res.board)
		result = ft_try(figures, res, 0, y + 1);
	return (result);
}
