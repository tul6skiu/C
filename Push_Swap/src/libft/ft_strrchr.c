/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:05:54 by wlister           #+#    #+#             */
/*   Updated: 2018/11/21 12:05:57 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *p;

	p = s;
	while (*p != '\0')
	{
		p++;
	}
	while (p >= s)
	{
		if (*p == (char)c)
		{
			return ((char *)p);
		}
		p--;
	}
	return (NULL);
}
