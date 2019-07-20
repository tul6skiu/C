/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:19:58 by wlister           #+#    #+#             */
/*   Updated: 2019/01/10 15:20:00 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_add_spaces_after(char *str, int n, t_codes *codes)
{
	char	*new;
	char	*tmp;
	int		i;

	new = (char *)malloc(sizeof(char) * (codes->len + n + 1));
	CHECK(new);
	tmp = new;
	while (*str)
		*tmp++ = *str++;
	i = -1;
	while (++i < n)
		*tmp++ = ' ';
	*tmp = '\0';
	return (new);
}

static char		*ft_add_spaces_before(char *str, int n, t_codes *codes)
{
	char	*new;
	char	*tmp;
	int		i;

	if (codes->spec == 1 && codes->len == 0 && str[0] == '\0')
		n = n - 1;
	new = (char *)malloc(sizeof(char) * ((int)ft_strlen(str) + n + 1));
	CHECK(new);
	tmp = new;
	i = -1;
	while (++i < n)
		*tmp++ = ' ';
	if (codes->prec == 0 && codes->len == 1 && str[0] == '0')
		*tmp++ = ' ';
	else
	{
		while (*str)
			*tmp++ = *str++;
	}
	*tmp = '\0';
	return (new);
}

char			*ft_aplly_width(char *str, t_codes *codes)
{
	int		diff;
	char	*tmp;

	tmp = NULL;
	diff = (codes->width - (int)ft_strlen(str));
	if (diff > 0)
	{
		if (ft_find_flag(codes, 3) && ft_find_flag(codes, 1))
			tmp = ft_add_spaces_after(str, diff, codes);
		else if (ft_find_flag(codes, 3) && (codes->prec == 0 ||\
										codes->spec == 0 ||\
										codes->spec == 1 ||\
										codes->spec == 2))
			tmp = ft_add_zero_before(str, diff, codes);
		else if (ft_find_flag(codes, 1))
			tmp = ft_add_spaces_after(str, diff, codes);
		else
			tmp = ft_add_spaces_before(str, diff, codes);
		if (codes->spec != 2)
			ft_strdel(&str);
	}
	else
		tmp = str;
	return (tmp);
}
