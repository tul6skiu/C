/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:52:28 by afalmer-          #+#    #+#             */
/*   Updated: 2018/12/03 12:52:29 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static void		ft_freelist_fd(t_list **list, int fd)
{
	t_list	*curr;
	t_list	*prev;

	curr = *list;
	prev = NULL;
	while (curr)
	{
		if (curr->content_size == (size_t)fd)
			break ;
		prev = curr;
		curr = curr->next;
	}
	if (prev)
		prev->next = curr->next;
	else
		*list = curr->next;
	ft_memdel(&curr->content);
	free(curr);
}

static t_list	*ft_getlist_fd(t_list **list, int fd)
{
	t_list	*temp;

	temp = *list;
	while (temp)
	{
		if (temp->content_size == (size_t)fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = ft_lstnew("", fd)))
		return (NULL);
	ft_lstadd(list, temp);
	temp = *list;
	return (temp);
}

static int		ft_get_result(char *temp, t_list *temp_list, char **line)
{
	if (temp && *temp)
	{
		if ((temp_list->content = ft_strchr(temp, '\n')) != NULL)
		{
			if (!(*line = ft_strsub(temp, 0, (char*)temp_list->content - temp))\
				|| !(temp_list->content = ft_strdup(temp_list->content + 1)))
			{
				ft_strdel(&temp);
				return (-1);
			}
		}
		else
		{
			if (!(*line = ft_strdup(temp)))
			{
				ft_strdel(&temp);
				return (-1);
			}
		}
		ft_strdel(&temp);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*temp_list;
	char			buffer[BUFF_SIZE + 1];
	char			*temp;
	size_t			bytes;

	if (!(temp_list = ft_getlist_fd(&list, fd)) || read(fd, buffer, 0) < 0)
		return (-1);
	temp = temp_list->content;
	while ((bytes = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[bytes] = '\0';
		if (!(temp = ft_strjoin(temp_list->content, buffer)))
			return (-1);
		ft_strdel((char**)&temp_list->content);
		if (ft_strchr(temp, '\n') != NULL)
			break ;
		temp_list->content = temp;
	}
	if ((bytes = ft_get_result(temp, temp_list, line)) == 1)
		return (1);
	else if (bytes > 1)
		return (-1);
	ft_freelist_fd(&list, fd);
	return (0);
}
