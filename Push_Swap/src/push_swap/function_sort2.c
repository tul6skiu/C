/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_sort2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:15:32 by wlister           #+#    #+#             */
/*   Updated: 2019/02/05 16:15:34 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			a_stack_push(int pivot, t_stack *a, t_stack *b, char **com)
{
	if (pivot == a->head->value)
	{
		a->head->sort = 1;
		push(a, b, com, "a");
	}
}

int				ft_part(t_stack *a, t_stack *b, char **com)
{
	int		size;

	size = 0;
	while (a->head->sort == 1)
		push(a, b, com, "a");
	size = stack_size(a);
	return (size);
}

void			sort_stack_a(t_stack *a, t_stack *b, char **com)
{
	int		size;
	int		pivot;

	pivot = 0;
	size = ft_part(a, b, com);
	if (a->flag == 0)
	{
		pivot = ft_find_median_val(a);
		ft_down(pivot, a, com);
	}
	else
	{
		pivot = a->head->value;
		shift_right(a, com, "a");
	}
	while (size-- - 1)
	{
		if (pivot < a->head->value)
			shift_right(a, com, "a");
		else
			push(a, b, com, "a");
	}
	if (serch_sort(a) == 1)
		ft_return_pivot(a, pivot, com, "a");
	a_stack_push(pivot, a, b, com);
}

void			sort_stack_b(t_stack *b, t_stack *a, char **com)
{
	int		size;
	int		tmp;
	int		pivot;
	int		i;

	i = 0;
	pivot = 0;
	tmp = 0;
	while (b->head->sort == 1)
		push(b, a, com, "b");
	size = stack_size(b);
	pivot = b->head->value;
	shift_right(b, com, "b");
	while (i < size - 1)
	{
		if (pivot < b->head->value)
			push(b, a, com, "b");
		else
			shift_right(b, com, "b");
		size--;
	}
	ft_return_pivot(b, pivot, com, "b");
	b_stack_push(pivot, b, a, com);
}
