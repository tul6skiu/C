/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:26:52 by afalmer-          #+#    #+#             */
/*   Updated: 2018/11/22 15:26:53 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*new_dst;

	new_dst = dst;
	while (len && (*new_dst++ = *src++))
		len--;
	if (len)
		while (--len)
			*new_dst++ = '\0';
	return (dst);
}
