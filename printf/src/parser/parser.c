/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:54:54 by vrestles          #+#    #+#             */
/*   Updated: 2019/01/10 13:56:42 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_search_func(int (*f[4])(char *str, t_codes *codes))
{
	f[0] = ft_search_flags;
	f[1] = ft_search_width;
	f[2] = ft_search_prec;
	f[3] = ft_search_size;
}

static int		ft_search_modif(char *str, t_codes *codes)
{
	int count;
	int val;
	int i;
	int	(*search[4])(char *str, t_codes *codes);

	ft_search_func(search);
	count = 0;
	i = 0;
	while (i < 4)
	{
		val = 0;
		if ((val = search[i](str, codes)) != 0)
		{
			count += val;
			str += val;
		}
		i++;
	}
	return (count);
}

int				ft_parser(char *str, t_codes *codes)
{
	int count;
	int c;

	count = 0;
	ft_struct_zero(codes);
	while (*str)
	{
		c = 0;
		if (ft_valid_spec(*str, codes))
			break ;
		if ((c = ft_search_modif(str, codes)))
		{
			count += c;
			str += c;
		}
		if (c == 0)
			break ;
	}
	c = ft_search_spec(str, codes);
	count += c;
	return (count);
}
