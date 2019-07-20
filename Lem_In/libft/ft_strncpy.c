/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 04:12:37 by gkoch             #+#    #+#             */
/*   Updated: 2018/11/22 17:38:05 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t size;

	size = ft_strlen(src);
	if (size > n)
		size = n;
	if (size != n)
		ft_memset(dest + size, '\0', n - size);
	return (ft_memcpy(dest, src, size));
}
