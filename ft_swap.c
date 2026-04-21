/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:34:34 by mgerard           #+#    #+#             */
/*   Updated: 2026/04/21 18:01:25 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(t_stack stack)
{
	stack -> tmp = stack.nbrs[0];
	stack.nbrs[0] = stack.nbrs[1];
	stack,nbrs[1] = stack -> tmp;
}

void	ft_swap_a(t_stack stack_a)
{
	ft_swap(stack_a);
}

void	ft_swap_b(t_stack stack_b)
{
	ft_swap(stack_b);
}
