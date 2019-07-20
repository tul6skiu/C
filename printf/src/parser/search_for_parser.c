/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:57:09 by vrestles          #+#    #+#             */
/*   Updated: 2019/01/10 14:00:43 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_search_flags(char *str, t_codes *codes)
{
	int flag;
	int i;
	int count;

	i = 0;
	count = 0;
	while ((flag = ft_is_flag(*str)) != 0)
	{
		if (!ft_find_flag(codes, flag))
		{
			codes->flags[flag - 1] = flag;
			i++;
		}
		count++;
		str++;
	}
	return (count);
}

int			ft_search_width(char *str, t_codes *codes)
{
	int width;
	int count;

	count = 0;
	if ((width = ft_atoi(str)) != 0)
	{
		codes->width = width;
		count += ft_count_sign_numbers(width);
	}
	return (count);
}

int			ft_search_prec(char *str, t_codes *codes)
{
	int len;
	int count;
	int c;

	count = 0;
	while (*str)
	{
		len = 0;
		c = 0;
		if (*str == '.')
		{
			len = ft_is_prec(++str, codes);
			c += len + 1;
			count += c;
		}
		else
			break ;
		str += len;
	}
	return (count);
}

int			ft_search_size(char *str, t_codes *codes)
{
	int size;
	int count;
	int c;

	count = 0;
	while (*str)
	{
		c = 0;
		size = 0;
		if ((size = ft_is_size(str)) != 0)
		{
			if (codes->size < size)
				codes->size = size;
			if (size == 1 || size == 4)
				c += 2;
			else
				c++;
			count += c;
		}
		else
			break ;
		str += c;
	}
	return (count);
}

int			ft_search_spec(char *str, t_codes *codes)
{
	int spec;
	int count;

	count = 0;
	spec = 0;
	if ((spec = ft_is_spec(*str, codes)) != 0)
	{
		codes->spec = spec;
		count++;
	}
	else if (*str == '\0')
		return (0);
	else
		count++;
	return (count);
}
