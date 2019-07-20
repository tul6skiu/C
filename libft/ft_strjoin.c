/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:14:46 by wlister           #+#    #+#             */
/*   Updated: 2018/11/22 13:14:48 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*resmerge;
	int		i;
	int		j;
	int		res_size;

	if (s1 == NULL || s2 == NULL)
		return (0);
	res_size = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	if (!(resmerge = (char *)malloc(sizeof(char) * res_size + 1)))
	{
		return (NULL);
	}
	while (s1[i])
	{
		resmerge[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		resmerge[i++] = s2[j++];
	}
	resmerge[i] = '\0';
	return (resmerge);
}
