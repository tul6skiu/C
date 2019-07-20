/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:42:32 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:53:29 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		clear_int(t_int **integer)
{
	t_int *next;

	while (*integer)
	{
		next = (*integer)->next;
		clear_one_int(integer);
		*integer = next;
	}
}
