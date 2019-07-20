/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:22:51 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 17:38:19 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int			check_char(const char *str, char i)
{
	int		n;

	n = 0;
	while (str[n])
	{
		if (str[n] == i)
			return (1);
		n++;
	}
	return (0);
}

void		clear_arr_ch(char ***str)
{
	int		n;

	n = 0;
	while ((*str)[n])
	{
		free((*str)[n]);
		(*str)[n] = NULL;
		n++;
	}
	free(*str);
	*str = NULL;
}

int			count_arr_ch(char **str)
{
	int		n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

void		eeerrror(void)
{
	ft_putendl("Chtoto POSHLO ne TAK ! SKA");
	exit(EXIT_FAILURE);
}
