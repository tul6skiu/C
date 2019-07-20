/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:15:56 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 21:21:12 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		put_step_ants(t_lem *lem, t_ants *ants)
{
	int		flag;

	flag = 0;
	while (ants)
	{
		if (ants->rooms != (lem->rooms - 1))
		{
			ants->rooms = ants->stream->used[ants->rooms];
			ft_putchar('L');
			ft_putnbr(ants->name);
			ft_putchar('-');
			ft_putstr(lem->row[ants->rooms].name);
			ft_putchar(' ');
			flag = 1;
		}
		ants = ants->next;
	}
	if (flag)
		ft_putchar('\n');
	return (flag);
}

void	to_let_out(t_lem *lem, t_groups *groups, t_ants **ants)
{
	t_groups	*group;
	int			flag;
	int			n;

	n = 0;
	flag = 1;
	while (flag)
	{
		flag = 0;
		group = groups;
		while (group)
		{
			if (group->count)
			{
				unshift_ant(ants, create_ant(++n, group->stream));
				group->count--;
				flag = 1;
			}
			group = group->next;
		}
		put_step_ants(lem, *ants);
	}
}

void	put_way_ants(t_lem *lem, t_stream *streams, t_groups *groups)
{
	t_ants	*ants;
	int		flag;

	ants = NULL;
	to_let_out(lem, groups, &ants);
	flag = 1;
	while (flag)
		flag = put_step_ants(lem, ants);
	clear_ants(&ants);
}

void	run_ants(t_lem *lem, t_stream **streams)
{
	t_groups		*groups;

	groups = NULL;
	set_groups(lem, *streams, &groups);
	put_way_ants(lem, *streams, groups);
	clear_groups(&groups);
}
