/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:19:32 by afalmer-          #+#    #+#             */
/*   Updated: 2018/11/26 17:19:33 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	char	*s_end;

	if (!s)
		return (NULL);
	s_end = (char*)s + ft_strlen(s) - 1;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while ((*s_end == ' ' || *s_end == '\n' || *s_end == '\t') && \
											(s_end - s) != -1)
		s_end--;
	if ((res = (char*)ft_memalloc(s_end - s + 2)) == NULL)
		return (NULL);
	res = ft_strncpy(res, s, s_end - s + 1);
	return (res);
}
