/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ovelar_function2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:19:31 by wlister           #+#    #+#             */
/*   Updated: 2019/02/11 18:19:32 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_word_count(char const *str, char c)
{
	int		cnt_word;
	int		flag_wrd;

	if (str == NULL)
		return (0);
	cnt_word = 0;
	while (*str == c)
	{
		str++;
	}
	flag_wrd = 0;
	while (*str)
	{
		if (*str != c && flag_wrd == 0)
		{
			flag_wrd = 1;
			cnt_word++;
		}
		else if (*str == c)
		{
			flag_wrd = 0;
		}
		str++;
	}
	return (cnt_word);
}

void	print_stack(t_stack *stack, char *stack_name)
{
	t_node	*curr;

	curr = stack->tail;
	ft_putstr(stack_name);
	ft_putstr("| ");
	while (curr != NULL)
	{
		ft_putnbr(curr->value);
		ft_putchar(' ');
		curr = curr->next;
	}
	ft_putstr("\n");
}

int		ft_check_value(t_stack *stack, int n)
{
	t_node	*tmp;

	tmp = NULL;
	if (stack == NULL)
		tmp = stack->head;
	while (tmp != NULL)
	{
		if (tmp->value == n)
			return (1);
		tmp = tmp->prev;
	}
	return (0);
}

int		ft_dublicat_string(t_stack *a)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = a->head;
	while (tmp != NULL)
	{
		tmp2 = tmp->prev;
		while (tmp2 != NULL)
		{
			if (tmp->value == tmp2->value)
			{
				ft_putstr("Error\n");
				ft_del_stack(&a);
				exit(1);
			}
			tmp2 = tmp2->prev;
		}
		tmp = tmp->prev;
	}
	return (1);
}

int		ft_dublicat_number(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				ft_putstr("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (1);
}
