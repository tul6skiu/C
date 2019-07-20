/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 04:15:04 by gkoch             #+#    #+#             */
/*   Updated: 2018/11/22 17:38:24 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*flag;
	int		n;

	str = (char *)s;
	flag = 0;
	n = 0;
	while (str[n])
	{
		if ((int)str[n] == c)
			flag = (char*)s + n;
		n++;
	}
	if ((int)str[n] == c)
		flag = (char*)s + n;
	return (flag);
}
