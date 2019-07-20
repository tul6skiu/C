/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:39:48 by wlister           #+#    #+#             */
/*   Updated: 2018/11/20 17:39:50 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t		i;
	char		*str1;
	const char	*str2;

	i = -1;
	str1 = destination;
	str2 = source;
	while (++i < n)
	{
		str1[i] = str2[i];
	}
	return (str1);
}
