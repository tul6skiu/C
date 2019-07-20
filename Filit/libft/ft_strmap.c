/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:02:58 by afalmer-          #+#    #+#             */
/*   Updated: 2018/11/26 13:02:59 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	char	*new_res;

	if (!f || !s)
		return (NULL);
	if ((res = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	new_res = res;
	while (*s)
		*new_res++ = f(*s++);
	return (res);
}
