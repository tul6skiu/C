/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:14:33 by afalmer-          #+#    #+#             */
/*   Updated: 2018/12/07 14:14:34 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map(char **map)
{
	while (*map)
	{
		ft_putstr(*map++);
		ft_putchar('\n');
	}
}

int		ft_sqrt(int nb)
{
	int		num;

	num = 1;
	while (num * num < nb)
		num++;
	return (num);
}

int		ft_solve_map(t_figures *figures, t_res *res, int count_tetr)
{
	res->board = ft_sqrt(count_tetr * 4);
	if (figures->length > res->board || figures->height > res->board)
		res->board = MAX(figures->length, figures->height);
	if (!(res->map = ft_create_map(res->map, res->board)))
		return (0);
	while (ft_try(figures, *res, 0, 0) == 0)
	{
		res->board += 1;
		if (!(res->map = ft_create_map(res->map, res->board)))
			return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	int			fd;
	t_figures	*figures;
	t_res		res;
	int			count_tetr;

	figures = NULL;
	res.map = NULL;
	if (ac != 2)
	{
		ft_putendl("usage: ./fillit input_file");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	if (!(count_tetr = ft_read_tetr(fd, &figures)) || count_tetr > 26)
	{
		ft_putendl("error");
		return (0);
	}
	if (ft_solve_map(figures, &res, count_tetr))
		ft_print_map(res.map);
	return (0);
}
