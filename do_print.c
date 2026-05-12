/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:37:59 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/13 00:01:30 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
		printf("[bench] strategy:  %s\n", strat);
		printf("[bench] total_ops:  %d\n", total_ops(val));
		printf("[bench] sa: %d  sb: %d  ss: ", val->sa, val->sb);
		printf("%d  pa: %d  pb: %d\n", val->ss, val->pa, val->pb);
		printf("[bench] ra: %d  rb: %d  rr: ", val->ra, val->rb);
		printf("%d  rra: %d  rrb: %d", val->rr, val->rra, val->rrb);
		printf("  rrr: %d\n", val->rrr);
	}
	free(val);
}
