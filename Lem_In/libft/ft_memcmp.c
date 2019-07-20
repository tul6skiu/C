/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 03:18:17 by gkoch             #+#    #+#             */
/*   Updated: 2018/11/22 17:35:22 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t count)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (count-- > 0)
		if (*s1++ != *s2++)
			return (s1[-1] - s2[-1]);
	return (0);
}
