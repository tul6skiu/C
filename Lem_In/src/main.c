/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:29:38 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/03 20:16:15 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		lem_in(void)
{
	t_lem		*lem;
	t_stream	*streams;
	t_char		*book;

	lim_read(&lem, &book);
	solve(lem, &streams);
	if (!streams)
		eeerrror();
	put_char(book);
	ft_putendl("");
	run_ants(lem, &streams);
	clear_char(&book);
	clear_streams(&streams);
	clear_lem(&lem);
}

int			main(void)
{
	lem_in();
	return (0);
}
