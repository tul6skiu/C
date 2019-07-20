/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 04:16:35 by gkoch             #+#    #+#             */
/*   Updated: 2018/11/22 17:38:33 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_count_s(char const *s, char c)
{
	int		item;
	int		n;

	item = 0;
	n = 0;
	while (s[n])
	{
		while (s[n] == c && s[n])
			n++;
		if (!s[n])
			break ;
		while (s[n] != c && s[n])
			n++;
		item++;
	}
	return (item);
}

static void	ft_adds(char *answer, char const *str, int end)
{
	int		n;

	n = -1;
	while (++n < end)
		answer[n] = str[n];
	answer[n] = '\0';
}

static int	write_lines(char const *s, char c, char **mas)
{
	int		item;
	int		n;
	int		start;

	n = 0;
	item = 0;
	while (s[n])
	{
		while (s[n] == c && s[n])
			n++;
		if (!s[n])
			break ;
		start = n;
		while (s[n] != c && s[n])
			n++;
		if (!(mas[item] = ft_strnew((size_t)(n - start + 1))))
			return (1);
		ft_adds(mas[item], s + start, n - start);
		item++;
	}
	mas[item] = 0;
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**answer;

	if (!s || !c)
		return (NULL);
	if (!(answer = (char**)malloc(sizeof(char*) * (ft_count_s(s, c) + 1))))
		return (NULL);
	if (write_lines(s, c, answer))
		return (NULL);
	return (answer);
}
