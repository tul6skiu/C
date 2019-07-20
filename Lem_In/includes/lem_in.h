/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoch <gkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:52:19 by gkoch             #+#    #+#             */
/*   Updated: 2019/04/06 21:20:58 by gkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft.h"
# include <fcntl.h>

typedef	struct			s_lem
{
	int					ants;
	int					rooms;
	struct s_row		*row;
	struct s_graf		*graf;
}						t_lem;

typedef struct			s_row
{
	int					id;
	char				*name;
	struct s_int		*line;
}						t_row;

typedef	struct			s_graf
{
	char				*start;
	char				*end;
	struct s_kin		*kin;
	struct s_rooms		*rooms;
}						t_graf;

typedef	struct			s_kin
{
	char				**name;
	struct s_kin		*next;
}						t_kin;

typedef	struct			s_rooms
{
	char				*name;
	struct s_rooms		*next;
}						t_rooms;

typedef struct			s_stream
{
	int					len;
	int					*used;
	struct s_int		*turn;
	struct s_stream		*next;
}						t_stream;

typedef struct			s_groups
{
	int					count;
	struct s_stream		*stream;
	struct s_groups		*next;
}						t_groups;

typedef struct			s_ants
{
	int					rooms;
	int					name;
	struct s_stream		*stream;
	struct s_ants		*next;
}						t_ants;

void					lim_read(t_lem **lem, t_char **book);
int						check_char(const char *str, char i);
void					eeerrror();
void					clear_arr_ch(char ***str);
int						count_arr_ch(char **str);
void					get_ants(t_lem **lem, t_char **book);
void					get_data(t_lem **lem, t_graf **graf, t_char **book);
int						check_tag(t_lem **lem, t_graf **graf, char **line,
								t_char **book);
void					get_connect(t_lem **lem, t_graf **graf, char **line);
void					get_comment(t_lem **lem, t_graf **graf, char **line);
void					get_list(t_lem **lem, t_graf *graf);
void					solve(t_lem *lem, t_stream **streams);
void					part2(t_lem *lem, t_stream *stream);
void					part1(t_lem *lem);
void					del_connecting(t_lem *lem, int *used);
void					run_ants(t_lem *lem, t_stream **streams);
void					set_groups(t_lem *lem, t_stream *streams,
								t_groups **groups);
t_lem					*create_lem();
t_kin					*create_kin(char **name);
t_graf					*create_graf();
t_rooms					*create_rooms(char *name);
t_ants					*create_ant(int name, t_stream	*stream);
t_groups				*create_group(t_stream *stream);
t_stream				*create_stream(int *used, t_int *turn);
int						push_rooms(t_rooms **begin_list, t_rooms *data);
int						push_stream(t_stream **begin_list, t_stream *data);
int						unshift_kin(t_kin **begin_list, t_kin **data);
int						unshift_rooms(t_rooms **begin_list, t_rooms **data);
int						unshift_stream(t_stream **begin_list, t_stream *data);
int						unshift_ant(t_ants **begin_list, t_ants *data);
int						unshift_groups(t_groups **begin_list, t_groups *data);
void					clear_graf(t_graf **graf);
void					clear_lem(t_lem **lem);
void					clear_streams(t_stream **streams);
void					clear_ants(t_ants **ants);
void					clear_groups(t_groups **groups);

#endif
