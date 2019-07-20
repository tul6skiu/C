/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:16:22 by wlister           #+#    #+#             */
/*   Updated: 2019/01/10 15:16:23 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_prefix(char *str)
{
	if (str[0] == '0' && str[1] == 'x')
		return (1);
	if (str[0] == '0' && str[1] == 'X')
		return (1);
	return (0);
}

char		*ft_reduce_prec(char *str, t_codes *codes)
{
	char	*new;

	new = ft_strsub(str, 0, codes->prec);
	return (new);
}

char		*ft_expand_prec(char *str, t_codes *codes)
{
	int		len;
	char	*new;
	int		diff;

	len = codes->len;
	if (codes->spec == 3)
		len = len - 2;
	if ((codes->spec == 8 || codes->spec == 9) && ft_check_prefix(str))
		len = len - 2;
	diff = codes->prec - len;
	if (diff > 0)
	{
		new = ft_add_zero_before(str, diff, codes);
		ft_strdel(&str);
	}
	else
		new = str;
	return (new);
}
