/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:48:22 by wlister           #+#    #+#             */
/*   Updated: 2018/11/20 20:48:24 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destination, const char *source, size_t n)
{
	size_t		i;

	i = -1;
	while (++i < n)
	{
		if (source[i])
		{
			destination[i] = source[i];
		}
		else
		{
			while (i < n)
			{
				destination[i++] = '\0';
			}
		}
	}
	return (destination);
}
