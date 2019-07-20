/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_date.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:09:07 by wlister           #+#    #+#             */
/*   Updated: 2019/01/14 15:10:58 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_strpst(char *str, const char *pst, unsigned int start,
						size_t len)
{
	int			i;
	size_t		len_str;
	size_t		len_pst;

	i = 0;
	len_str = ft_strlen(str);
	len_pst = ft_strlen(pst);
	if ((start + len) > len_str || len > len_pst)
		return (NULL);
	while (i < (int)len)
	{
		str[start] = pst[i];
		start++;
		i++;
	}
	return (str);
}

static void		ft_modif_invalid_date(char *str, char c)
{
	int		check;

	if (c == 'd')
	{
		check = ft_atoi(str);
		if (check > 31)
			ft_strcpy(str, "31");
	}
	if (c == 'm')
	{
		check = ft_atoi(str);
		if (check > 12)
			ft_strcpy(str, "12");
	}
}

static char		*ft_create_date_string(char *str)
{
	char	*date;
	char	*day;
	char	*month;
	char	*year;

	year = ft_strsub(str, 0, 4);
	month = ft_strsub(str, 4, 2);
	ft_modif_invalid_date(month, 'm');
	day = ft_strsub(str, 6, 2);
	ft_modif_invalid_date(day, 'd');
	date = ft_char_into_string('.', 10);
	ft_strpst(date, year, 0, 4);
	ft_strpst(date, month, 5, 2);
	ft_strpst(date, day, 8, 2);
	ft_strdel(&year);
	ft_strdel(&month);
	ft_strdel(&day);
	return (date);
}

int				ft_print_date(unsigned int nb, t_codes *codes)
{
	int		count;
	char	*date;
	char	*def_min;
	char	*def_max;
	char	*res;

	def_min = "19700101";
	def_max = "99991231";
	date = NULL;
	codes->len = ft_count_unsign_numbers(nb);
	if (codes->len < 8)
		res = ft_create_date_string(def_min);
	else if (codes->len > 8)
		res = ft_create_date_string(def_max);
	else
	{
		date = ft_ull_itoa(nb);
		res = ft_create_date_string(date);
		ft_strdel(&date);
	}
	count = ft_print_string(res, codes);
	ft_strdel(&res);
	return (count);
}
