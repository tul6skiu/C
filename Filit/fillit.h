/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:15:14 by afalmer-          #+#    #+#             */
/*   Updated: 2018/12/07 14:15:16 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"

# define MAX(a, b) a > b ? a : b

typedef struct			s_figures
{
	int					length;
	int					height;
	char				**tetrimino;
	struct s_figures	*next;
}						t_figures;

typedef struct			s_coord
{
	int					start_i;
	int					end_i;
	int					start_j;
	int					end_j;
}						t_coord;

typedef struct			s_res
{
	char				**map;
	int					board;
}						t_res;

typedef struct			s_counts
{
	int					lines;
	int					sharp;
}						t_counts;

int						ft_read_tetr(int fd, t_figures **figures);
int						ft_tetr_to_list(t_figures **figures, char **tetr, \
										int *count_sharp, int count_lines);
int						ft_check_line(char *str, int count_lines, \
												int *count_sharp);
void					ft_free_multiarr(char **tetr);
int						ft_create_figures(t_figures **figures, char **result);
void					ft_size_tetr(char **tetr, int *i, int *j);
int						ft_check_valid(char **result, int i, int j);
void					ft_add_figure(t_figures **figures, t_figures *new);
char					**ft_cut_tetr(char **tetr);
char					**ft_set_tetr(char **tetr, t_coord coord);
void					ft_cut_col(char **tetr, int *start, int *end);
void					ft_cut_lines(char **tetr, int *start, int *end);
int						ft_solve_map(t_figures *figures, t_res *res, \
													int count_tetr);
int						ft_sqrt(int nb);
char					**ft_create_map(char **map, int board);
void					ft_point(char **res, int board);
int						ft_try(t_figures *figures, t_res res, int x, int y);
int						ft_check(t_figures *figures, t_res res, int x, int y);
void					ft_set(t_figures *figures, t_res res, int x, int y);
void					ft_reset(t_figures *figures, t_res res, int x, int y);

#endif
