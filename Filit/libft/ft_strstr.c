/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:30:40 by afalmer-          #+#    #+#             */
/*   Updated: 2018/11/23 12:30:41 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*res_hs;
	char	*new_hs;
	char	*new_needle;

	if (!*needle)
		return ((char*)haystack);
	res_hs = NULL;
	while (*haystack)
	{
		new_hs = (char*)haystack;
		res_hs = (char*)haystack;
		new_needle = (char*)needle;
		while (*new_hs && *new_hs == *new_needle)
		{
			new_hs++;
			new_needle++;
		}
		if (!*new_needle)
			break ;
		res_hs = NULL;
		haystack++;
	}
	return (res_hs);
}
