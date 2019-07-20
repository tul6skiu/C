/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:06:05 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 20:25:06 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_char		*str_to_char(char *str)
{
	t_char		*head;
	t_char		*next;
	int			n;

	n = 0;
	if (!str || !str[n])
		return (NULL);
	head = create_char(str[n++]);
	next = head;
	while (str[n])
	{
		next->next = create_char(str[n]);
		next = next->next;
		n++;
	}
	return (head);
}
