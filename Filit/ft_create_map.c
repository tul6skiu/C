/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:35:33 by afalmer-          #+#    #+#             */
/*   Updated: 2018/12/13 18:35:33 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_point(char **res, int board)
{
	int		i;
	int		j;

	i = 0;
	while (i < board)
	{
		j = 0;
		while (j < board)
		{
			res[i][j] = '.';
			j++;
		}
		res[i][j] = '\0';
		i++;
	}
}

char	**ft_create_map(char **map, int board)
{
	int			i;
	char		**res;

	if (map)
		free(map);
	if (!(res = (char**)malloc(sizeof(char*) * (board + 1) + \
				sizeof(char) * board * (board + 1))))
		return (0);
	res[0] = (char*)(res + board + 1);
	i = 1;
	while (i < board)
	{
		res[i] = res[0] + i * (board + 1);
		i++;
	}
	res[i] = NULL;
	ft_point(res, board);
	return (res);
}
