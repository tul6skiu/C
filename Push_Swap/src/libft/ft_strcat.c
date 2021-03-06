/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:57:46 by wlister           #+#    #+#             */
/*   Updated: 2018/11/20 20:57:48 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*p;

	p = s1;
	while (*p)
	{
		p++;
	}
	while (*s2)
	{
		*p++ = *s2++;
	}
	*p = '\0';
	return (s1);
}
