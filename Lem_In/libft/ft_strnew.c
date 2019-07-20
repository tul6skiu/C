/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 04:13:36 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 18:05:45 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_memset(str, 0, size + 1);
	return (str);
}
