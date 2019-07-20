/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:31:14 by vrestles          #+#    #+#             */
/*   Updated: 2019/01/10 13:31:18 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_char_into_string(char c, int n)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * (n + 1));
	CHECK(new);
	i = 0;
	while (i < n)
	{
		new[i] = c;
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char		*ft_modif_c(char *str, t_codes *codes)
{
	char	*res;

	res = NULL;
	if (codes->width != 0)
		res = ft_aplly_width(str, codes);
	else
		res = str;
	return (res);
}

int				ft_print_c(va_list ap, t_codes *codes)
{
	char	*str;
	int		count;
	char	*res;

	if (codes->spec == 0)
	{
		if (codes->oth != '\0')
			str = ft_char_into_string(codes->oth, 1);
		else
			return (0);
	}
	else
	{
		if (codes->size == 3)
			str = code_to_utf8(va_arg(ap, unsigned int));
		else
			str = ft_char_into_string(va_arg(ap, int), 1);
	}
	codes->len = (int)ft_strlen(str);
	res = ft_modif_c(str, codes);
	count = ft_print_string(res, codes);
	ft_strdel(&res);
	return (count);
}
