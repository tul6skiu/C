/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:55:48 by wlister           #+#    #+#             */
/*   Updated: 2019/01/18 12:55:50 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "../src/libft/includes/libft.h"

void	ft_start_sort(t_stack *a, t_stack *b, char **com)
{
	emptying_stack(a, b, com);
	ft_optimizator(com);
	ft_putstr(*com);
}

void	ft_сlean_stack(t_stack *a, t_stack *b, char **com)
{
	ft_del_stack(&a);
	ft_del_stack(&b);
	ft_strdel(com);
}

int		main(int argc, char **argv)
{
	char		*com;
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	com = ft_strnew(0);
	ft_error_params(argc);
	if (argc == 2)
	{
		a = ft_stack_from_string(argv[1]);
		ft_dublicat_string(a);
	}
	else
	{
		argv++;
		if (ft_is_number_p(argv) == 1)
		{
			if (ft_dublicat_number(argc - 1, argv) == 1)
				a = ft_simple_stack(argc, (char **)argv);
		}
	}
	b = create_stack();
	ft_start_sort(a, b, &com);
	ft_сlean_stack(a, b, &com);
	return (0);
}
