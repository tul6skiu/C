/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 03:15:37 by gkoch             #+#    #+#             */
/*   Updated: 2018/11/22 17:35:08 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = (void*)malloc(sizeof(void) * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
