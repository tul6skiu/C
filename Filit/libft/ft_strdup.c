/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:21:47 by afalmer-          #+#    #+#             */
/*   Updated: 2018/11/22 14:21:48 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

char	*ft_strdup(const char *s1)
{
	char	*res;
	char	*p;

	if ((res = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)) == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	p = res;
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (res);
}
