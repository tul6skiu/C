/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specificator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:00:58 by vrestles          #+#    #+#             */
/*   Updated: 2019/01/10 14:17:47 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_upper_spec(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "CSDOUF";
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_valid_spec(char c, t_codes *codes)
{
	char	*str;
	int		i;

	i = 0;
	str = "cspdiouxXfbk";
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		if (ft_upper_spec(c) && ft_toupper(str[i]) == c)
		{
			codes->size = 3;
			return (i + 1);
		}
		i++;
	}
	return (0);
}

int			ft_is_spec(char c, t_codes *codes)
{
	int spec;

	spec = 0;
	if ((spec = ft_valid_spec(c, codes)) != 0)
		return (spec);
	else
		codes->oth = c;
	return (0);
}
