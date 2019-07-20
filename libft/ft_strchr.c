/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:54:23 by wlister           #+#    #+#             */
/*   Updated: 2018/11/21 11:54:24 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*res;
	char	c2;

	res = (char *)s;
	c2 = (char)c;
	while (*res != '\0')
	{
		if (*res == (char)c2)
			return ((char *)res);
		res++;
	}
	if (*res == (char)c)
	{
		return ((char *)res);
	}
	return (NULL);
}
