/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_plus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:52:10 by wlister           #+#    #+#             */
/*   Updated: 2019/01/10 13:52:13 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*re_first_by_plus(char *str, char c)
{
	char	*tmp;
	char	*one;
	int		len;

	len = (int)ft_strlen(str);
	one = ft_char_into_string(c, 1);
	if (str[len - 1] == ' ')
		tmp = ft_strjoin(one, ft_strsub(str, 0, len - 1));
	else
		tmp = ft_strjoin(one, str);
	ft_strdel(&one);
	ft_strdel(&str);
	return (tmp);
}

static char		*ft_add_plus(char *str, t_codes *codes, char c)
{
	char	*tmp;

	tmp = str;
	if (str[0] == ' ')
	{
		while (*str == ' ')
			str++;
		str--;
		*str = c;
	}
	else if (str[0] == '0' && codes->width > codes->len &&
			codes->prec == 0)
		str[0] = c;
	else
		tmp = re_first_by_plus(str, c);
	return (tmp);
}

char			*ft_aplly_plus(char *str, t_codes *codes)
{
	char	*tmp;

	if ((ft_find_flag(codes, 2) && ft_find_flag(codes, 4)) ||
	ft_find_flag(codes, 2))
		tmp = ft_add_plus(str, codes, '+');
	else
		tmp = ft_add_plus(str, codes, ' ');
	return (tmp);
}
