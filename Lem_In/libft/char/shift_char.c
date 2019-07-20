/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:59:42 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:59:57 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	shift_char(t_char **letter)
{
	t_char	*update;
	char	answer;

	if (!*initgroups)
		return (-2);
	answer = (*letter)->letter;
	update = (*letter)->next;
	free(*letter);
	*letter = update;
	return (answer);
}
