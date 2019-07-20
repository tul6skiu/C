/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:33:24 by afalmer-          #+#    #+#             */
/*   Updated: 2018/11/23 15:33:25 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*res_hs;
	char	*new_hs;
	char	*new_needle;
	size_t	new_len;

	if (!*needle)
		return ((char*)haystack);
	res_hs = NULL;
	while (*haystack && len--)
	{
		new_hs = (char*)haystack;
		res_hs = (char*)haystack;
		new_needle = (char*)needle;
		new_len = len + 1;
		while (*new_hs && *new_hs == *new_needle && new_len--)
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
