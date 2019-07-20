/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:56:29 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 20:02:45 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		clear_char(t_char **letter)
{
	t_char *next;

	while (*letter)
	{
		next = (*letter)->next;
		clear_one_char(letter);
		*letter = next;
	}
}
