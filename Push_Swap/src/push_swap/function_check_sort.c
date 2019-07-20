/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:25:49 by wlister           #+#    #+#             */
/*   Updated: 2019/01/17 19:25:51 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		is_sort(char **argv)
{
	int		i;

	i = 1;
	while (argv[i + 1] != NULL)
	{
		if (argv[i][0] > argv[i + 1][0])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_is_sort_down(t_stack *stack)
{
	t_node	*tmp;
	int		n;
	int		i;

	tmp = NULL;
	if (stack == NULL || stack->size == 0)
		return (1);
	tmp = stack->head;
	n = tmp->value;
	i = 1;
	tmp = tmp->prev;
	while (tmp)
	{
		if (n > tmp->value)
		{
			n = tmp->value;
			i++;
		}
		else
			break ;
		tmp = tmp->prev;
	}
	if (stack->size == i)
		return (1);
	return (0);
}

int		serch_min(t_stack *a)
{
	int		i;
	int		size;
	t_node	*tmp;
	int		index;
	int		min;

	min = 0;
	i = 0;
	index = 0;
	size = a->size;
	tmp = a->head;
	min = a->head->value;
	while (i < size)
	{
		if (min > tmp->value)
		{
			min = tmp->value;
			index = i;
		}
		tmp = tmp->prev;
		i++;
	}
	return (index);
}

int		serch_max(t_stack *b)
{
	int		i;
	int		size;
	t_node	*tmp;
	int		index;
	int		max;

	i = 0;
	index = 0;
	size = b->size;
	tmp = b->head;
	max = b->head->value;
	while (i < size)
	{
		if (max < tmp->value)
		{
			max = tmp->value;
			index = i;
		}
		tmp = tmp->prev;
		i++;
	}
	return (index);
}

int		serch_sort(t_stack *stack)
{
	t_node	*tmp;
	int		i;
	int		size;

	i = 0;
	size = stack->size;
	tmp = stack->head;
	while (i < size)
	{
		if (tmp->sort == 1)
		{
			return (1);
		}
		tmp = stack->head->prev;
		i++;
	}
	return (0);
}
