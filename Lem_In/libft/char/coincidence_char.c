/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coincidence_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:55:56 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:57:00 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_char	*coincidence_char(t_char *letter, int coincidence)
{
	while (letter)
	{
		if (letter->letter == coincidence)
			return (letter);
		letter = letter->next;
	}
	return (NULL);
}
