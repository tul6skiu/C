/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ovelar_function3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:36:51 by wlister           #+#    #+#             */
/*   Updated: 2019/02/13 13:36:53 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_error_params(int argc)
{
	if (argc == 1)
	{
		ft_putstr("Error\n");
		exit(1);
	}
}

void	ft_del_stack(t_stack **stack)
{
	t_node	*tmp;
	t_node	*del;

	tmp = NULL;
	del = NULL;
	if (*stack == NULL || *stack == NULL)
		return ;
	tmp = (*stack)->head;
	while (tmp != NULL)
	{
		del = tmp;
		tmp = tmp->prev;
		free(del);
		del = NULL;
	}
	free(*stack);
	*stack = NULL;
}
