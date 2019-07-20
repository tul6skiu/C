/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:09:56 by gkoch             #+#    #+#             */
/*   Updated: 2019/01/20 13:50:12 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_scut(char const *s, unsigned int start, char c)
{
	char	*answer;
	int		n;
	size_t	i;

	n = 0;
	while (s[n] != c && s[n])
		n++;
	answer = ft_strnew(n);
	if ((s == NULL) || !answer)
		return (NULL);
	i = 0;
	while (s[start] && (s[start] != c))
		answer[i++] = s[start++];
	answer[i] = 0;
	return (answer);
}
