/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:09:15 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/17 17:13:52 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	current_len;
	int	*nbrs;
	int	*index;
	int	tmp;
	int	tmpi;
}			t_stack;

typedef struct s_op_count
{
	char	in_stack;
	float	disorder_val;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_op_count;

char	**to_join_to_split(char **av);
float	disorder(t_stack *a);
int		is_double_num(t_stack *a, char **av);
int		ft_parse(char **argv, t_stack *stacks_ab, int is_flag, int is_bench);
void	ft_swap(t_stack *stacks_ab, int is_bench, t_op_count *values);
void	rrotate(t_stack *stacks_ab, t_op_count *values, int is_bench);
void	rotate(t_stack *stacks_ab, t_op_count *values, int is_bench);
void	pushup_tmp(t_stack *stack);
void	pushdown_tmp(t_stack *stack);
void	push(t_stack *stacks_ab, int is_bench, t_op_count *values);
void	pushfrom(t_stack *stacks_ab, int is_bench, t_op_count *values);
void	bubble_sort(t_stack *a);
void	selection_sort(t_stack *ab, int is_bench, t_op_count *val);
void	quick_sortish(t_stack *ab, t_op_count *val, int is_bench);
void	quick_sort_test2(t_stack *a, t_stack *b);
int		sorted(t_stack *a);
t_stack	*init_pivot_history(t_stack *a);
//int	partition(t_stack *a, t_stack *b, t_stack *pi, char a_or_b);
int		all_in_history(t_stack *a, t_stack *b, t_stack *pi, char in_stack);
void	quicksort(t_stack *a, t_stack *b, t_stack *pi, char in_stack);
//int		is_in_history(t_stack *pi_, t_stack *a, t_stack *b, char , int j);
void	chunck_divide(t_stack *ab, t_op_count *values, int is_bench);
void	flag_detect(char **argv, int mode_return[]);
int		flag_validation(int ac, char **argv, t_stack *stacks_ab);
int		ft_is_int(char *str);
void	do_print(t_op_count *values, int is_bench, char *strat);
void	destroy_all(char **args, t_stack *stacks_ab, int crash);
int		ft_sqrt(int nb);
void	index_select(t_stack *a);
void	radix_sort(t_stack *ab, t_op_count *values, int is_bench);
#endif
