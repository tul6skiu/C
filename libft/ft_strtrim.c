/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:28:14 by wlister           #+#    #+#             */
/*   Updated: 2018/11/22 14:28:18 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len--;
	if (len < 0)
		str = (char *)malloc(sizeof(char) * 1);
	if (len >= i)
	{
		if (!(str = (char *)malloc(sizeof(char) * (len - i + 2))))
			return (NULL);
		while (i <= len)
			str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}
