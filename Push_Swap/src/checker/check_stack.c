/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:26:12 by wlister           #+#    #+#             */
/*   Updated: 2019/01/17 19:26:14 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sorted_out(t_stack *a, t_stack *b)
{
	if (ft_is_sort(a) == 1 && b->size == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

void	ft_fill_stack(t_stack *a, t_stack *b, char *line)
{
	while (get_next_line(0, &line) > 0)
	{
		if (ft_valid_instruction(line) == 1)
			ft_execution_instruction(a, b, line);
	}
}

void	ft_part2(int argc, char **argv, t_stack **a)
{
	if (ft_is_number(argv) == 1)
	{
		if (ft_dublicat_number(argc - 1, argv) == 1)
		{
			*a = ft_simple_stack(argc, (char **)argv);
		}
	}
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*line;

	line = NULL;
	a = NULL;
	ft_error_params(argc);
	if (argc == 2)
	{
		a = ft_stack_from_string(argv[1]);
		ft_dublicat_string(a);
	}
	else
	{
		argv++;
		ft_part2(argc, argv, &a);
	}
	b = create_stack();
	ft_fill_stack(a, b, line);
	ft_sorted_out(a, b);
	return (0);
}
