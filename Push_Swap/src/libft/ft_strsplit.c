/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:00:24 by wlister           #+#    #+#             */
/*   Updated: 2018/11/23 11:00:26 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int		ft_word_count(char const *str, char c)
{
	int		cnt_word;
	int		flag_wrd;

	if (str == NULL)
		return (0);
	cnt_word = 0;
	while (*str == c)
	{
		str++;
	}
	flag_wrd = 0;
	while (*str)
	{
		if (*str != c && flag_wrd == 0)
		{
			flag_wrd = 1;
			cnt_word++;
		}
		else if (*str == c)
		{
			flag_wrd = 0;
		}
		str++;
	}
	return (cnt_word);
}

static	int		ft_s_word(char const *str, char c)
{
	int size;

	size = 0;
	while (*str == c)
	{
		str++;
	}
	while (*str != c && *str)
	{
		size++;
		str++;
	}
	return (size);
}

static void		ft_freewords(char ***words)
{
	if (**words)
	{
		while (**words)
		{
			ft_strdel(*words);
			(*words)++;
		}
		free(*words);
		*words = NULL;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	**res_words;
	char	*new_s;

	if (!s)
		return (NULL);
	new_s = (char *)s;
	if (!(words = (char**)malloc(sizeof(char*) * (ft_word_count(s, c) + 1))))
		return (NULL);
	res_words = words;
	while (*new_s && words)
	{
		while (*new_s && *new_s == c)
			new_s++;
		if (*new_s)
		{
			if (!(*res_words++ = ft_strsub(s, new_s - s, ft_s_word(new_s, c))))
				ft_freewords(&words);
			else
				*res_words = NULL;
			new_s = new_s + ft_s_word(new_s, c);
		}
	}
	return (words);
}
