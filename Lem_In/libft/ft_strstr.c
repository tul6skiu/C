/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 04:17:45 by gkoch             #+#    #+#             */
/*   Updated: 2018/11/22 17:38:36 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	char	*str1;
	char	*str2;

	str1 = (char*)str;
	str2 = (char*)to_find;
	i = 0;
	if (str2[0] == '\0')
		return (str1);
	while (str1[i])
	{
		j = 0;
		if (str1[i] == str2[j])
		{
			while (str2[j] && (str2[j] == str1[i + j]))
				j++;
			if (str2[j] == '\0')
				return (str1 + i);
		}
		i++;
	}
	return (NULL);
}
