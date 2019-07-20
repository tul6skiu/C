/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:10:35 by wlister           #+#    #+#             */
/*   Updated: 2018/11/21 13:10:37 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;
	int			found;

	i = -1;
	found = 1;
	if (!ft_strlen(l))
		return ((char *)b);
	while (*(b + ++i) && i < len)
	{
		j = 0;
		if (*(b + i) == *(l + 0))
		{
			k = i;
			found = 1;
			while (*(b + k) && *(l + j) && j < len && k < len)
				if (*(b + k++) != *(l + j++))
					found = 0;
			if (found && !*(l + j))
				return ((char *)b + i);
		}
	}
	return (NULL);
}
