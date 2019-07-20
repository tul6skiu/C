/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:24:39 by wlister           #+#    #+#             */
/*   Updated: 2018/11/20 17:24:41 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = src;
	i = 0;
	while (i < len)
		*(ptr + i++) = (unsigned char)c;
	return (src);
}
