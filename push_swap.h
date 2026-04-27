/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:09:15 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/27 15:04:09 by mgerard          ###   ########.fr       */
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

void	ft_parse(char **argv, t_stack *stacks_ab);
void	ft_swap(t_stack *a, t_stack *b, char in_stack);
void	rotate(t_stack *a, t_stack *b, char stack_in);
void	rrotate(t_stack *a, t_stack *b, char in_stack);
void	pushup_tmp(t_stack *stack);
void	pushdown_tmp(t_stack *stack);
void	push(t_stack *a, t_stack *b, char in_stack);
void	pushfrom(t_stack *a, t_stack *b, char in_stack);
void	bubble_sort(t_stack *a);
void	selection_sort(t_stack *a, t_stack *b);
void	quick_sort_test2(t_stack *a, t_stack *b);
int	is_sorted(t_stack *a, t_stack *b);
t_stack	*init_pivot_history(t_stack *a);
//int	partition(t_stack *a, t_stack *b, t_stack *pi, char a_or_b);
int	all_in_history(t_stack *a, t_stack *b, t_stack *pi, char in_stack);
void	quicksort(t_stack *a, t_stack *b, t_stack *pi, char in_stack);
int	is_in_history(t_stack *pi_history, t_stack *a, t_stack *b, char a_or_b, int j);
void	chunck_divide(t_stack *a, t_stack *b);
#endif
