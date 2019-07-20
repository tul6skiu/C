/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:47:59 by wlister           #+#    #+#             */
/*   Updated: 2018/11/20 18:48:01 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*ftr1;
	unsigned char	*ftr2;

	i = 0;
	ftr1 = (unsigned char *)str1;
	ftr2 = (unsigned char *)str2;
	while (i < n && ftr1[i] == ftr2[i])
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return (ftr1[i] - ftr2[i]);
}
