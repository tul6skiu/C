/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:32:23 by vrestles          #+#    #+#             */
/*   Updated: 2019/01/10 13:40:10 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_to_address(void *smth, t_codes *codes)
{
	unsigned long long	nb;
	char				*tmp;
	char				*res;
	char				*add;

	add = NULL;
	nb = (unsigned long long)(&(*smth));
	if (nb == 0 && codes->prec == -1)
	{
		tmp = (char *)malloc(sizeof(char) * 3);
		CHECK(tmp);
		ft_strcpy(tmp, "0x");
	}
	else
	{
		add = ft_convert_to_any_base16(nb, 16, 0);
		tmp = ft_strjoin("0x", add);
		ft_strdel(&add);
	}
	codes->len = (int)ft_strlen(tmp);
	if (codes->prec > 0)
		res = ft_expand_prec(tmp, codes);
	else
		res = tmp;
	return (res);
}

static char		*ft_to_string(char *str, t_codes *codes)
{
	char	*res;
	char	*tmp;
	char	strnull[7];

	if (str == NULL)
	{
		ft_strcpy(strnull, "(null)");
		tmp = strnull;
	}
	else
		tmp = str;
	if (codes->prec == -1)
		res = ft_strnew(1);
	else
		res = tmp;
	codes->len = (int)ft_strlen(res);
	return (res);
}

int				ft_string_modificators(char *str, t_codes *codes)
{
	char	*res;
	char	*prec;
	int		count;

	if (codes->spec == 2 && codes->size != 3 &&
		codes->prec > 0 && codes->prec < codes->len)
		prec = ft_reduce_prec(str, codes);
	else
		prec = str;
	if (codes->width != 0)
		res = ft_aplly_width(prec, codes);
	else
		res = prec;
	count = ft_print_string(res, codes);
	if (codes->spec != 2 || (codes->spec == 2 && codes->size == 3) ||
		(codes->spec == 2 && codes->prec == -1))
		ft_strdel(&res);
	return (count);
}

int				ft_print_sp(va_list ap, t_codes *codes)
{
	int		count;
	char	*tmp;

	count = 0;
	tmp = NULL;
	if (codes->spec == 2 && codes->size == 3)
	{
		tmp = string_to_utf8(va_arg(ap, unsigned int *), codes);
		codes->len = (int)ft_strlen(tmp);
	}
	else if (codes->spec == 3)
		tmp = ft_to_address(va_arg(ap, char *), codes);
	else
		tmp = ft_to_string(va_arg(ap, char *), codes);
	count = ft_string_modificators(tmp, codes);
	return (count);
}
