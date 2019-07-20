/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:14:11 by wlister           #+#    #+#             */
/*   Updated: 2019/01/10 14:14:13 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_add_zero_before_lx(char *str, int n)
{
	char	*new;
	char	*tmp;
	int		i;

	new = (char *)malloc(sizeof(char) * ((int)ft_strlen(str) + n + 1));
	CHECK(new);
	tmp = new;
	if (str[0] == '0' && str[1] == 'x')
	{
		*tmp++ = '0';
		*tmp++ = 'x';
		str = str + 2;
	}
	i = -1;
	while (++i < n)
		*tmp++ = '0';
	while (*str)
		*tmp++ = *str++;
	*tmp = '\0';
	return (new);
}

static char		*ft_add_zero_before_bx(char *str, int n)
{
	char	*new;
	char	*tmp;
	int		i;

	new = (char *)malloc(sizeof(char) * ((int)ft_strlen(str) + n + 1));
	CHECK(new);
	tmp = new;
	if (str[0] == '0' && str[1] == 'X')
	{
		*tmp++ = '0';
		*tmp++ = 'X';
		str = str + 2;
	}
	i = -1;
	while (++i < n)
		*tmp++ = '0';
	while (*str)
		*tmp++ = *str++;
	*tmp = '\0';
	return (new);
}

static char		*ft_add_zero_before_simple(char *str, int n, t_codes *codes)
{
	char	*new;
	char	*tmp;
	int		i;

	if (codes->spec == 1 && codes->len == 0 && str[0] == '\0')
		n = n - 1;
	new = (char *)malloc(sizeof(char) * ((int)ft_strlen(str) + n + 1));
	CHECK(new);
	tmp = new;
	if (codes->sign == 1)
	{
		*tmp++ = '-';
		str++;
	}
	i = -1;
	while (++i < n)
		*tmp++ = '0';
	while (*str)
		*tmp++ = *str++;
	*tmp = '\0';
	return (new);
}

char			*ft_add_zero_before(char *str, int n, t_codes *codes)
{
	char	*res;

	res = NULL;
	if (codes->spec == 3 || codes->spec == 8)
		res = ft_add_zero_before_lx(str, n);
	else if (codes->spec == 9)
		res = ft_add_zero_before_bx(str, n);
	else
		res = ft_add_zero_before_simple(str, n, codes);
	return (res);
}
