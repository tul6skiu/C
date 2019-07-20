/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sorts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:31:42 by wlister           #+#    #+#             */
/*   Updated: 2019/02/05 13:31:44 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	*ft_com_stack(char *str, char *n)
{
	char	*src;
	char	*res;

	src = ft_strjoin(str, n);
	res = ft_strjoin(src, "\n");
	ft_strdel(&src);
	return (res);
}

void	swap(t_stack *a, char **com, char *n)
{
	int		res;
	char	*tmp;
	char	*src;

	res = swap_int(a);
	if (res == 1)
	{
		tmp = ft_com_stack("s", n);
		src = ft_strjoin(*com, tmp);
		ft_strdel(&(*com));
		ft_strdel(&tmp);
		*com = src;
	}
}

void	shift_right(t_stack *a, char **com, char *n)
{
	int		res;
	char	*tmp;
	char	*src;

	res = shift_right_int(a);
	if (res == 1)
	{
		tmp = ft_com_stack("r", n);
		src = ft_strjoin(*com, tmp);
		ft_strdel(&(*com));
		ft_strdel(&tmp);
		*com = src;
	}
}

void	shift_left(t_stack *a, char **com, char *n)
{
	int		res;
	char	*tmp;
	char	*src;

	res = shift_left_int(a);
	if (res == 1)
	{
		tmp = ft_com_stack("rr", n);
		src = ft_strjoin(*com, tmp);
		ft_strdel(&(*com));
		ft_strdel(&tmp);
		*com = src;
	}
}

void	print_two_stacks(t_stack *a, t_stack *b)
{
	print_stack(a, "a");
	print_stack(b, "b");
}
