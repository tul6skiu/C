/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:20:39 by wlister           #+#    #+#             */
/*   Updated: 2018/11/21 11:20:40 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;

	dlen = ft_strlen(dst);
	if (size < dlen)
		return (size + ft_strlen(src));
	while (*dst)
		dst++;
	while (*src && size - 1 > dlen)
	{
		*dst++ = *src++;
		dlen++;
	}
	*dst = '\0';
	return (dlen + ft_strlen(src));
}
