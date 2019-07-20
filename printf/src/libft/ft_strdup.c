/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:07:36 by vrestles          #+#    #+#             */
/*   Updated: 2018/11/27 19:03:28 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char *dst;

	dst = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, s1);
	return (dst);
}
