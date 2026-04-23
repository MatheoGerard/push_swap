/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:09:15 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/23 15:25:15 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	current_len;
	int	*nbrs;
	int	tmp;
}			t_stack;

void	ft_parse(char **argv, t_stack *stacks_ab);
void	ft_swap(t_stack *stack);
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);
void	pushup_tmp(t_stack *stack);
void	pushdown_tmp(t_stack *stack);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	bubble_sort(t_stack *a);
void	selection_sort(t_stack *a, t_stack *b);
void	quick_sort_test2(t_stack *a, t_stack *b);
int	is_sorted(t_stack *a);
#endif
