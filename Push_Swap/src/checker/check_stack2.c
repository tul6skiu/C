/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:16:25 by wlister           #+#    #+#             */
/*   Updated: 2019/02/13 14:16:27 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "../src/libft/includes/libft.h"

int		ft_check_range(long long int nb)
{
	if (nb >= 2147483647 && nb <= -2147483648)
		return (0);
	else
		return (1);
}

int		ft_is_number(char **argv)
{
	long long int	i;

	i = 0;
	while (*argv)
	{
		i = ft_atoi(*argv);
		if ((i != 0) || (**argv == '0'))
		{
			if (ft_check_range(i) == 0)
			{
				ft_putstr("Error\n");
				exit(1);
			}
		}
		else
			return (0);
		argv++;
	}
	return (1);
}

int		ft_valid_instruction(char *line)
{
	char	*insruct;

	insruct = "pa pb sa sb ra rb rra rrb";
	if (ft_strstr(insruct, line) != NULL)
	{
		return (1);
	}
	else
	{
		ft_putstr("Error\n");
		exit(1);
	}
	return (0);
}

void	ft_execution_instruction(t_stack *a, t_stack *b, char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		push_int(a, b);
	if (ft_strcmp(line, "pb") == 0)
		push_int(b, a);
	if (ft_strcmp(line, "sa") == 0)
		swap_int(a);
	if (ft_strcmp(line, "sb") == 0)
		swap_int(b);
	if (ft_strcmp(line, "ra") == 0)
		shift_right_int(a);
	if (ft_strcmp(line, "rb") == 0)
		shift_right_int(b);
	if (ft_strcmp(line, "rra") == 0)
		shift_left_int(a);
	if (ft_strcmp(line, "rrb") == 0)
		shift_left_int(b);
}
