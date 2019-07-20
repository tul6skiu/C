/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:09:54 by wlister           #+#    #+#             */
/*   Updated: 2019/02/11 13:09:55 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			ft_check_range1(char *str)
{
	if (ft_atoi(str) >= 2147483647 && ft_atoi(str) <= -2147483648)
		return (0);
	return (1);
}

void		ft_check_valid(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) || !ft_strcmp(str[i], "0"))
		{
			if (ft_check_range1(str[i]) == 0)
			{
				ft_putstr("Error\n");
				exit(1);
			}
		}
		else
		{
			ft_putstr("Error\n");
			exit(1);
		}
		i++;
	}
}

t_stack		*ft_make_stack(t_stack *stack, int count, const char **str)
{
	int		i;
	t_node	*tmp;

	i = count;
	stack = create_stack();
	tmp = stack->head;
	while (i != 0)
	{
		tmp = create_node();
		tmp->value = ft_atoi(str[i - 1]);
		add_to_head(stack, tmp);
		tmp = tmp->prev;
		i--;
	}
	return (stack);
}

t_stack		*ft_stack_from_string(char *str)
{
	char		**new;
	int			count;
	int			i;
	t_stack		*stack;
	t_stack		*stack2;

	i = 0;
	stack2 = create_stack();
	stack = NULL;
	count = ft_word_count(str, ' ');
	if (count == 0)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	new = ft_strsplit(str, ' ');
	ft_check_valid(new);
	stack2 = ft_make_stack(stack, count, (const char **)new);
	return (stack2);
}

t_stack		*ft_simple_stack(int argc, char **argv)
{
	t_stack		*new_stack;
	t_node		*tmp;

	new_stack = create_stack();
	tmp = new_stack->head;
	while (argc > 1)
	{
		tmp = create_node();
		tmp->value = ft_atoi(argv[argc - 2]);
		add_to_head(new_stack, tmp);
		tmp = tmp->prev;
		argc--;
	}
	return (new_stack);
}
