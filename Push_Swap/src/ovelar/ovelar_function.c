/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ovelar_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:03:14 by wlister           #+#    #+#             */
/*   Updated: 2019/02/11 17:03:18 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		push_int(t_stack *first, t_stack *second)
{
	t_node	*tmp;

	tmp = pop_stack(first);
	if (tmp != NULL)
	{
		add_to_head(second, tmp);
		return (1);
	}
	return (0);
}

int		swap_int(t_stack *a)
{
	t_node	*left;
	t_node	*right;

	if (a->size < 2 || a == NULL)
		return (0);
	left = a->head;
	right = a->head->prev;
	left->prev = right->prev;
	if (right->prev != NULL)
		left->prev->next = left;
	right->prev = left;
	left->next = right;
	right->prev = NULL;
	if (a->size == 2)
		a->head = left;
	return (1);
}

int		shift_right_int(t_stack *a)
{
	t_node	*tail;
	t_node	*head;

	if (a->size > 1)
	{
		tail = a->tail;
		head = a->head;
		a->head = a->head->prev;
		a->head->next = NULL;
		head->prev = NULL;
		head->next = tail;
		tail->prev = head;
		a->tail = head;
		return (1);
	}
	return (0);
}

int		shift_left_int(t_stack *a)
{
	t_node	*tail;
	t_node	*head;

	if (a->size > 1)
	{
		tail = a->tail;
		head = a->head;
		a->tail = tail->next;
		a->tail->prev = NULL;
		tail->next = NULL;
		tail->prev = head;
		head->next = tail;
		a->head = tail;
		return (1);
	}
	return (0);
}

int		ft_is_sort(t_stack *stack)
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
		if (n < tmp->value)
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
