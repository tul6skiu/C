/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimiz_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:27:36 by wlister           #+#    #+#             */
/*   Updated: 2019/02/13 12:27:38 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_changeable_str(char **com, char *str, char *mode)
{
	char	*std;
	char	*std2;
	char	*new;

	*str = '\0';
	std = ft_strdup(*com);
	std2 = ft_strdup(str + ft_strlen(mode));
	new = ft_strjoin(std, std2);
	ft_strdel(&std);
	ft_strdel(&std2);
	ft_strdel(&(*com));
	*com = new;
}

void	ft_optimizator_next3(char **com)
{
	char	*str;

	str = ft_strstr(*com, "\nrb\nrrb");
	if (str != NULL)
	{
		ft_changeable_str(com, str, "\nrb\nrrb");
		ft_optimizator_next3(com);
	}
	str = ft_strstr(*com, "\nrrb\nrb");
	if (str != NULL)
	{
		ft_changeable_str(com, str, "\nrrb\nrb");
		ft_optimizator_next3(com);
	}
}

void	ft_optimizator_next2(char **com)
{
	char	*str;

	str = ft_strstr(*com, "\nra\nrra");
	if (str != NULL)
	{
		ft_changeable_str(com, str, "\nra\nrra");
		ft_optimizator_next2(com);
	}
	str = ft_strstr(*com, "\nrra\nra");
	if (str != NULL)
	{
		ft_changeable_str(com, str, "\nrra\nra");
		ft_optimizator_next2(com);
	}
	else
		ft_optimizator_next3(com);
}

void	ft_optimizator_next(char **com)
{
	char	*str;

	str = ft_strstr(*com, "\nsa\nsb");
	if (str != NULL)
	{
		ft_changeable_str(com, str, "\nsa\nsb");
		ft_optimizator_next(com);
	}
	str = ft_strstr(*com, "\nsb\nsa");
	if (str != NULL)
	{
		ft_changeable_str(com, str, "\nsb\nsa");
		ft_optimizator_next(com);
	}
	else
		ft_optimizator_next2(com);
}

void	ft_optimizator(char **com)
{
	char	*str;

	str = ft_strstr(*com, "\npa\npb");
	if (str != NULL)
	{
		ft_changeable_str(com, str, "\npa\npb");
		ft_optimizator(com);
	}
	str = ft_strstr(*com, "\npb\npa");
	if (str != NULL)
	{
		ft_changeable_str(com, str, "\npb\npa");
		ft_optimizator(com);
	}
	else
		ft_optimizator_next(com);
}
