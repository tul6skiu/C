/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:44:38 by afalmer-          #+#    #+#             */
/*   Updated: 2018/11/26 13:44:39 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	char			*new_res;
	unsigned int	i;

	i = 0;
	if (!f || !s)
		return (NULL);
	if ((res = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	new_res = res;
	while (*s)
		*new_res++ = f(i++, *s++);
	return (res);
}
