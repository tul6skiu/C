/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 03:10:47 by gkoch             #+#    #+#             */
/*   Updated: 2018/11/22 17:34:37 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_list	*ft_lstcpy(t_list *list)
{
	t_list	*newlist;

	newlist = ft_lstnew(list->content, \
						list->content_size);
	if (newlist)
		return (newlist);
	return (NULL);
}
