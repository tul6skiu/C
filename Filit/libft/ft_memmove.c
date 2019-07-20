/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:21:55 by afalmer-          #+#    #+#             */
/*   Updated: 2018/11/21 17:21:59 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;

	if (dst <= src)
	{
		new_dst = (unsigned char*)dst;
		new_src = (unsigned char*)src;
		while (len--)
			*new_dst++ = *new_src++;
	}
	else
	{
		new_dst = (unsigned char*)dst + len - 1;
		new_src = (unsigned char*)src + len - 1;
		while (len--)
			*new_dst-- = *new_src--;
	}
	return (dst);
}
