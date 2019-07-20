/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:47:25 by wlister           #+#    #+#             */
/*   Updated: 2019/02/05 13:47:31 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		stack_size(t_stack *stack)
{
	t_node	*tmp;
	int		size;

	size = 0;
	tmp = stack->head;
	while (tmp != NULL && tmp->sort == 0)
	{
		tmp = tmp->prev;
		size++;
	}
	return (size);
}

void	ft_return_pivot(t_stack *b, int pivot, char **com, char *n)
{
	t_node	*tmp;
	int		i;
	int		j;
	int		size;
	int		index;

	i = 0;
	j = 0;
	index = 0;
	size = b->size;
	tmp = b->head;
	while (tmp->value != pivot)
	{
		i++;
		tmp = tmp->prev;
	}
	if (i > size / 2)
	{
		while (i < size && ++i)
			shift_left(b, com, n);
	}
	else
		while (i--)
			shift_right(b, com, n);
}

void	sort_medium_max(t_stack *a, t_stack *b, char **com)
{
	int		i;
	int		size;

	size = b->size;
	while (!size)
	{
		i = serch_max(b);
		if (i > size / 2)
			while (i < size && ++i)
			{
				shift_left(b, com, "b");
			}
		else
			while (i--)
			{
				shift_right(b, com, "b");
			}
		if (size != 0)
		{
			push(b, a, com, "b");
		}
		size--;
	}
}

void	sort_medium_min(t_stack *a, t_stack *b, char **com)
{
	int		i;
	int		size;

	size = a->size;
	while (!ft_is_sort(a))
	{
		i = serch_min(a);
		if (i > size / 2)
			while (i < size && ++i)
				shift_left(a, com, "a");
		else
			while (i--)
				shift_right(a, com, "a");
		if (a->size != 0)
			push(a, b, com, "a");
		size--;
	}
}

void	emptying_stack(t_stack *a, t_stack *b, char **com)
{
	if (a->size == 5)
		sort_medium_min(a, b, com);
	while (!(ft_is_sort(a) && ft_is_sort_down(b)))
	{
		while (!ft_is_sort(a))
		{
			if (a->size == 25)
			{
				sort_medium_min(a, b, com);
			}
			sort_stack_a(a, b, com);
		}
		a->flag = 1;
		while (!ft_is_sort_down(b))
		{
			sort_stack_b(b, a, com);
		}
	}
	while (b->size != 0)
	{
		push(b, a, com, "b");
	}
}
