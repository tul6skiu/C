/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serch_pivot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:10:46 by wlister           #+#    #+#             */
/*   Updated: 2019/02/13 19:10:47 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int				ft_abs(int num)
{
	if (num < 0)
		return ((-1) * num);
	return (num);
}

int				ft_sum(t_stack *stack)
{
	t_node	*tmp;
	int		res;

	tmp = stack->head;
	res = 0;
	while (tmp != NULL)
	{
		res += tmp->value;
		tmp = tmp->prev;
	}
	return (res);
}

int				ft_find_median_val(t_stack *stack)
{
	int		sum;
	int		avg;
	int		diff;
	int		pos;
	t_node	*tmp;

	sum = ft_sum(stack);
	avg = sum / stack->size;
	tmp = stack->head;
	diff = ft_abs(avg - tmp->value);
	pos = tmp->value;
	while (tmp != NULL)
	{
		if (ft_abs(avg - tmp->value) < diff)
		{
			diff = ft_abs(avg - tmp->value);
			pos = tmp->value;
		}
		tmp = tmp->prev;
	}
	return (pos);
}

void			ft_down(int pivot, t_stack *a, char **com)
{
	int		i;
	int		size;
	t_node	*tmp;

	i = 0;
	size = a->size;
	tmp = a->head;
	while (tmp != NULL)
	{
		if (tmp->value == pivot)
			break ;
		i++;
		tmp = tmp->prev;
	}
	if (i >= size / 2)
	{
		while (i < size - 1 && ++i)
			shift_left(a, com, "a");
	}
	else
	{
		i++;
		while (i--)
			shift_right(a, com, "a");
	}
}
