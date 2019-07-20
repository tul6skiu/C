/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatiomn_sort2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:36:50 by wlister           #+#    #+#             */
/*   Updated: 2019/02/05 13:36:51 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	free_node(t_node *node)
{
	free(node);
}

void	push(t_stack *first, t_stack *second, char **com, char *n)
{
	int		res;
	char	*tmp;
	char	*src;

	res = push_int(first, second);
	if (res == 1)
	{
		tmp = ft_com_stack("p", n);
		src = ft_strjoin(*com, tmp);
		ft_strdel(&(*com));
		ft_strdel(&tmp);
		*com = src;
	}
}

void	b_stack_push(int pivot, t_stack *b, t_stack *a, char **com)
{
	if (pivot == b->head->value)
	{
		b->head->sort = 1;
		push(b, a, com, "b");
	}
}

int		ft_check_range_p(long long int nb)
{
	if (nb >= 2147483647 && nb <= -2147483648)
		return (0);
	else
		return (1);
}

int		ft_is_number_p(char **argv)
{
	long long int	i;

	i = 0;
	while (*argv)
	{
		i = ft_atoi(*argv);
		if ((i != 0) || (**argv == '0'))
		{
			if (ft_check_range_p(i) == 0)
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
		argv++;
	}
	return (1);
}
