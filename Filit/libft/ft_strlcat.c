/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:31:51 by afalmer-          #+#    #+#             */
/*   Updated: 2018/11/22 19:31:52 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;

	dst_size = ft_strlen(dst);
	if (size < dst_size)
		return (size + ft_strlen(src));
	while (*dst)
		dst++;
	while (*src && size - 1 > dst_size)
	{
		*dst++ = *src++;
		dst_size++;
	}
	*dst = '\0';
	return (dst_size + ft_strlen(src));
}
