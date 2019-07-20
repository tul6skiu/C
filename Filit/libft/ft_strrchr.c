/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:14:23 by afalmer-          #+#    #+#             */
/*   Updated: 2018/11/23 12:14:24 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*new_s;
	char	*res_s;

	new_s = (char*)s;
	res_s = NULL;
	while (*new_s)
	{
		if (*new_s == (char)c)
			res_s = new_s;
		new_s++;
	}
	if (*new_s == c)
		return (new_s);
	return (res_s);
}
