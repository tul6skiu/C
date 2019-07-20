/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:57:17 by wlister           #+#    #+#             */
/*   Updated: 2018/11/20 17:57:20 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	size_t		i;
	char		*ftr1;
	const char	*ftr2;

	i = 0;
	ftr1 = (char *)destination;
	ftr2 = (char *)source;
	if (ftr2 > ftr1)
		while (i < n)
		{
			ftr1[i] = ftr2[i];
			i++;
		}
	else
		while (n--)
		{
			*(ftr1 + n) = *(ftr2 + n);
		}
	return (destination);
}
