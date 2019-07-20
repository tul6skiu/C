/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 04:04:27 by gkoch             #+#    #+#             */
/*   Updated: 2018/11/22 17:37:35 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*answer;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	answer = ft_strnew((size_t)ft_strlen(s1) \
				+ (size_t)ft_strlen(s2) + 1);
	if (!answer)
		return (NULL);
	i = -1;
	while (s1[++i])
		answer[i] = s1[i];
	j = -1;
	while (s2[++j])
		answer[i + j] = s2[j];
	answer[i + j] = '\0';
	return (answer);
}
