/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 04:11:33 by gkoch             #+#    #+#             */
/*   Updated: 2018/11/22 17:37:56 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && (nb > j))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
