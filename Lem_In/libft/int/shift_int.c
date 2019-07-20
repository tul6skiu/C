/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:39:27 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:39:42 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	shift_int(t_int **integer)
{
	t_int	*update;
	int		answer;

	if (!*initgroups)
		return (-2);
	answer = (*integer)->integer;
	update = (*integer)->next;
	free(*integer);
	*integer = update;
	return (answer);
}
