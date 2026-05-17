/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:37:59 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/17 17:13:22 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_ops(t_op_count *val)
{
	int	tot;

	tot = 0;
	tot += val->pa;
	tot += val->pb;
	tot += val->ra;
	tot += val->rb;
	tot += val->rr;
	tot += val->rra;
	tot += val->rrb;
	tot += val->rrr;
	tot += val->sa;
	tot += val->sb;
	tot += val->ss;
	return (tot);
}

void	do_print(t_op_count *val, int is_bench, char *strat)
{
	if (is_bench)
	{
		ft_printf(2, "[bench] disorder:  %f%%\n", val->disorder_val);
		ft_printf(2, "[bench] strategy:  %s\n", strat);
		ft_printf(2, "[bench] total_ops:  %d\n", total_ops(val));
		ft_printf(2, "[bench] sa: %d  sb: %d  ss: ", val->sa, val->sb);
		ft_printf(2, "%d  pa: %d  pb: %d\n", val->ss, val->pa, val->pb);
		ft_printf(2, "[bench] ra: %d  rb: %d  rr: ", val->ra, val->rb);
		ft_printf(2, "%d  rra: %d  rrb: %d", val->rr, val->rra, val->rrb);
		ft_printf(2, "  rrr: %d\n", val->rrr);
	}
}
