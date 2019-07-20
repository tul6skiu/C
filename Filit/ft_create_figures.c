/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_figures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:53:07 by afalmer-          #+#    #+#             */
/*   Updated: 2018/12/14 12:53:08 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_add_figure(t_figures **figures, t_figures *new)
{
	t_figures	*temp;

	temp = *figures;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*figures = new;
}

int		ft_check_valid(char **result, int i, int j)
{
	if (i * j == 6)
	{
		if (MAX(i, j) == i)
		{
			if (result[1][0] == '.' && (result[0][1] == '.' || \
				result[1][1] == '.' || result[2][1] == '.'))
				return (0);
			if (result[1][1] == '.' && (result[0][0] == '.' || \
				result[1][0] == '.' || result[2][0] == '.'))
				return (0);
		}
		else
		{
			if (result[0][1] == '.' && (result[1][0] == '.' || \
				result[1][1] == '.' || result[1][2] == '.'))
				return (0);
			if (result[1][1] == '.' && (result[0][0] == '.' || \
				result[0][1] == '.' || result[0][2] == '.'))
				return (0);
		}
	}
	return (1);
}

void	ft_size_tetr(char **tetr, int *i, int *j)
{
	*i = 0;
	while (tetr[*i])
	{
		*j = 0;
		while (tetr[*i][*j])
		{
			(*j)++;
		}
		(*i)++;
	}
}

int		ft_create_figures(t_figures **figures, char **result)
{
	t_figures	*new;
	int			i;
	int			j;

	if (!result)
		return (0);
	ft_size_tetr(result, &i, &j);
	if (!(new = (t_figures*)malloc(sizeof(t_figures))) || i * j > 6)
		return (0);
	if (!ft_check_valid(result, i, j))
		return (0);
	new->tetrimino = result;
	new->height = i;
	new->length = j;
	new->next = NULL;
	ft_add_figure(figures, new);
	return (1);
}
