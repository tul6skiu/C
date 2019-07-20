/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:31:59 by wlister           #+#    #+#             */
/*   Updated: 2018/11/21 14:32:02 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t		*str;

	str = (size_t *)malloc(size);
	if (!str)
	{
		return (NULL);
	}
	else
	{
		ft_bzero(str, size);
	}
	return (str);
}
