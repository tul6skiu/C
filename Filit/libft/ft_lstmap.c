/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:42:06 by afalmer-          #+#    #+#             */
/*   Updated: 2018/11/29 16:42:07 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_lstdel_content(void *content, size_t size)
{
	if (content && size)
	{
		ft_memdel(&content);
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*temp;

	if (lst && f)
	{
		if ((res = f(lst)) == NULL)
			return (NULL);
		temp = res;
		while (lst->next)
		{
			if ((temp->next = f(lst->next)) == NULL)
			{
				ft_lstdel(&res, ft_lstdel_content);
				return (NULL);
			}
			lst = lst->next;
			temp = temp->next;
		}
		return (res);
	}
	return (NULL);
}
