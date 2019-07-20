/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 03:19:06 by gkoch             #+#    #+#             */
/*   Updated: 2018/11/22 17:35:28 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	size_t			n;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)destptr;
	str2 = (unsigned char*)srcptr;
	n = 0;
	while (n < num)
	{
		str1[n] = str2[n];
		n++;
	}
	return (destptr);
}
