/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:46:54 by wlister           #+#    #+#             */
/*   Updated: 2018/11/20 17:46:56 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	i = -1;
	ptr = destination;
	while (++i < n)
	{
		*(ptr + i) = *((unsigned char *)source + i);
		if (*((unsigned char *)source + i) == (unsigned char)c)
			return (destination + i + 1);
	}
	return (NULL);
}
