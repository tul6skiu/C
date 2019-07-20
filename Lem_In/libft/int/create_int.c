/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:36:51 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:40:32 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_int	*create_int(int integer)
{
	t_int	*new;

	if (!(new = (t_int*)ft_memalloc(sizeof(t_int))))
		exit(EXIT_FAILURE);
	new->integer = integer;
	new->next = NULL;
	return (new);
}
