/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:43:41 by wlister           #+#    #+#             */
/*   Updated: 2019/01/18 12:43:44 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_node		*create_node(void)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->value = 0;
	tmp->sort = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_stack		*create_stack(void)
{
	t_stack		*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	tmp->size = 0;
	tmp->flag = 0;
	tmp->head = NULL;
	tmp->tail = NULL;
	return (tmp);
}

void		add_to_head(t_stack *stack, t_node *node)
{
	if (stack->head == NULL)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->prev = stack->head;
		stack->head->next = node;
		stack->head = node;
	}
	stack->size++;
}

void		add_to_tail(t_stack *stack, int numb)
{
	t_node	*node;

	node = create_node();
	if (stack->tail == NULL)
	{
		stack->tail = node;
		stack->head = node;
	}
	else
	{
		node->prev = stack->tail;
		stack->tail->next = node;
		stack->tail = node;
	}
	node->value = numb;
	stack->size++;
}

t_node		*pop_stack(t_stack *stack)
{
	t_node	*head;

	if (stack->size == 0)
	{
		return (0);
	}
	head = stack->head;
	stack->head = stack->head->prev;
	head->prev = NULL;
	if (stack->head != NULL)
	{
		stack->head->next = NULL;
	}
	stack->size--;
	if (stack->size == 0)
		stack->tail = NULL;
	return (head);
}
