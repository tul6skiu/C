/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:27:14 by wlister           #+#    #+#             */
/*   Updated: 2019/01/14 15:27:17 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_last_case(unsigned int code)
{
	char	*str;

	str = ft_strnew(4);
	str[0] = 0xF0 | (code >> 18);
	str[1] = 0x80 | ((code >> 12) & 0x3F);
	str[2] = 0x80 | ((code >> 6) & 0x3F);
	str[3] = 0x80 | (code & 0x3F);
	return (str);
}

char			*code_to_utf8(unsigned int code)
{
	char	*str;

	if (code <= 0x7F)
	{
		str = ft_strnew(1);
		str[0] = code;
	}
	else if (code <= 0x7FF)
	{
		str = ft_strnew(2);
		str[0] = 0xC0 | (code >> 6);
		str[1] = 0x80 | (code & 0x3F);
	}
	else if (code <= 0xFFFF)
	{
		str = ft_strnew(3);
		str[0] = 0xE0 | (code >> 12);
		str[1] = 0x80 | ((code >> 6) & 0x3F);
		str[2] = 0x80 | (code & 0x3F);
	}
	else
		str = ft_last_case(code);
	return (str);
}

static char		*ft_make_string(unsigned int *code, t_codes *codes)
{
	char	*str;
	char	*res;
	char	*tmp;
	int		len;
	char	*new;

	len = 0;
	new = NULL;
	tmp = NULL;
	res = ft_strnew(1);
	while (*code)
	{
		tmp = code_to_utf8(*code);
		len += (int)ft_strlen(tmp);
		if (len <= codes->prec || codes->prec == 0)
			str = ft_strjoin(res, tmp);
		else
			str = ft_strdup(res);
		new = res;
		ft_strdel(&new);
		res = str;
		ft_strdel(&tmp);
		code++;
	}
	return (res);
}

char			*string_to_utf8(unsigned int *code, t_codes *codes)
{
	char	*res;

	res = NULL;
	if (code == NULL)
		res = ft_strdup("(null)");
	else
		res = ft_make_string(code, codes);
	return (res);
}
