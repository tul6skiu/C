/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlister <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:26:37 by wlister           #+#    #+#             */
/*   Updated: 2019/01/17 19:26:39 by wlister          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include "../src/libft/includes/libft.h"
# include "../src/libft/includes/get_next_line.h"

typedef struct		s_node {
	int				value;
	int				sort;
	int				flag;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_stack {
	int				size;
	int				flag;
	t_node			*head;
	t_node			*tail;
}					t_stack;

t_node				*create_node();
t_stack				*create_stack();
char				*ft_com_stack(char *str, char *n);
int					ft_is_sort(t_stack *stack);
void				add_to_head(t_stack *stack, t_node *node);
void				add_to_tail(t_stack *stack, int numb);
int					swap_int(t_stack *a);
void				swap(t_stack *a, char **com, char *n);
void				shift_left(t_stack *a, char **com, char *n);
int					shift_left_int(t_stack *a);
void				shift_right(t_stack *a, char **com, char *n);
int					shift_right_int(t_stack *a);
int					push_int(t_stack *first, t_stack *second);
void				push(t_stack *first, t_stack *second, char **com, char *n);
void				print_two_stacks(t_stack *a, t_stack *b);
void				free_node(t_node *node);
void				b_stack_push(int pivot, t_stack *b, t_stack *a, char **com);
void				a_stack_push(int pivot, t_stack *a, t_stack *b, char **com);
int					ft_check_range_p(long long int nb);
int					ft_is_number_p(char **argv);
int					is_sort(char **argv);
int					ft_is_sort_down(t_stack *stack);
int					serch_min(t_stack *a);
int					serch_max(t_stack *b);
int					serch_sort(t_stack *stack);
int					stack_size(t_stack *stack);
void				ft_return_pivot(t_stack *b, int pivot, char **com, char *n);
void				sort_medium_max(t_stack *a, t_stack *b, char **com);
void				sort_medium_min(t_stack *a, t_stack *b, char **com);
void				emptying_stack(t_stack *a, t_stack *b, char **com);
void				ft_changeable_str(char **com, char *str, char *mode);
void				ft_optimizator_next3(char **com);
void				ft_optimizator_next2(char **com);
void				ft_optimizator_next(char **com);
void				ft_optimizator(char **com);
void				sort_stack_a(t_stack *a, t_stack *b, char **com);
void				sort_stack_b(t_stack *b, t_stack *a, char **com);
void				ft_start_sort(t_stack *a, t_stack *b, char **com);
void				ft_сlean_stack(t_stack *a, t_stack *b, char **com);
void				ft_sorted_out(t_stack *a, t_stack *b);
void				ft_fill_stack(t_stack *a, t_stack *b, char *line);
void				ft_part2(int argc, char **argv, t_stack **a);
int					ft_check_range(long long int nb);
int					ft_is_number(char **argv);
int					ft_valid_instruction(char *line);
void				ft_execution_instruction(t_stack *a, t_stack *b,
											char *line);
int					ft_check_range1(char *str);
void				ft_check_valid(char **str);
t_stack				*ft_make_stack(t_stack *stack, int	count,
								const char **str);
t_stack				*ft_stack_from_string(char *str);
t_stack				*ft_simple_stack(int argc, char **argv);
t_node				*pop_stack(t_stack *stack);
int					ft_word_count(char const *str, char c);
void				print_stack(t_stack *stack, char *stack_name);
int					ft_check_value(t_stack *stack, int n);
int					ft_dublicat_string(t_stack *a);
int					ft_dublicat_number(int argc, char **argv);
void				ft_error_params(int	argc);
void				ft_del_stack(t_stack **stack);
int					ft_abs(int num);
int					ft_find_median_val(t_stack *stack);
int					ft_sum(t_stack *stack);
int					ft_part(t_stack *a, t_stack *b, char **com);
void				ft_down(int pivot, t_stack *a, char **com);
void				ft_part3(int pivot, t_stack *a, char **com);

#endif
