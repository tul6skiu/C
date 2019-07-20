/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:57:53 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:58:06 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_char	*create_char(int letter)
{
	t_char	*new;

	if (!(new = (t_char*)ft_memalloc(sizeof(t_char))))
		exit(EXIT_FAILURE);
	new->letter = letter;
	new->next = NULL;
	return (new);
}
