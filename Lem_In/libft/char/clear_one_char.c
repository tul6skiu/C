/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_one_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:52:22 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 19:55:48 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		clear_one_char(t_char **letter)
{
	(void)(*letter)->letter;
	(*letter)->next = NULL;
	free(*letter);
	(*letter) = NULL;
}
