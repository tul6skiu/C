/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:11:41 by afalmer-          #+#    #+#             */
/*   Updated: 2018/11/23 11:11:43 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*new_s;

	new_s = (char*)s;
	while (*new_s)
	{
		if (*new_s == (char)c)
			return (new_s);
		new_s++;
	}
	if (*new_s == c)
		return (new_s);
	return (NULL);
}
