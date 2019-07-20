/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_one_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:34:07 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:35:47 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		clear_one_int(t_int **integer)
{
	(void)(*integer)->integer;
	(*integer)->next = NULL;
	free(*integer);
	(*integer) = NULL;
}
