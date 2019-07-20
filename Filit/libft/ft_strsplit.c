/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:12:00 by afalmer-          #+#    #+#             */
/*   Updated: 2018/11/26 18:12:01 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_words(const char *str, char sep)
{
	int		count;
	int		pos;

	count = 0;
	pos = OUT;
	while (*str)
	{
		if (*str != sep && pos == OUT)
		{
			count++;
			pos = IN;
		}
		else if (*str == sep && pos == IN)
			pos = OUT;
		str++;
	}
	return (count);
}

static int	ft_wlen(const char *s, char c)
{
	char	*new_s;

	new_s = (char*)s;
	while (*new_s && *new_s != c)
		new_s++;
	return (new_s - s);
}

static void	ft_freewords(char ***words)
{
	if (*words)
	{
		while (**words)
		{
			free(**words);
			(*words)++;
		}
		free(*words);
		*words = NULL;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	**new_words;
	char	*new_s;

	if (!s)
		return (NULL);
	new_s = (char*)s;
	if (!(words = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
		return (NULL);
	new_words = words;
	while (*new_s && words)
	{
		while (*new_s && *new_s == c)
			new_s++;
		if (*new_s)
		{
			if (!(*new_words++ = ft_strsub(s, new_s - s, ft_wlen(new_s, c))))
				ft_freewords(&words);
			else
				new_s = new_s + ft_wlen(new_s, c);
		}
	}
	if (words)
		*new_words = NULL;
	return (words);
}
