/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/20 17:22:04 by username         #+#    #+#              */
/*   Updated: 2026/05/20 18:50:37 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_simple(char **argv, t_stack *stacks_ab, int is_bench, int is_adpt)
{
	t_op_count	values[1];

	if (!is_adpt && !ft_parse(argv, stacks_ab, 1, is_bench))
		return (-1);
	init_values(stacks_ab, values);
	selection_sort(stacks_ab, is_bench, values);
	if (is_adpt)
		do_print(values, is_bench, "Adaptive / O(n²)");
	else
		do_print(values, is_bench, "Simple / O(n²)");
	return (0);
}

int	do_medium(char **argv, t_stack *stacks_ab, int is_bench, int is_adpt)
{
	t_op_count	values[1];

	if (!is_adpt && !ft_parse(argv, stacks_ab, 1, is_bench))
		return (-1);
	init_values(stacks_ab, values);
	chunck_divide(stacks_ab, values, is_bench);
	if (is_adpt)
		do_print(values, is_bench, "Adaptive / O(n√n)");
	else
		do_print(values, is_bench, "Medium / O(n√n)");
	return (0);
}

int	do_complex(char **argv, t_stack *stacks_ab, int is_bench, int is_adpt)
{
	t_op_count	values[1];

	if (!is_adpt && !ft_parse(argv, stacks_ab, 1, is_bench))
		return (-1);
	init_values(stacks_ab, values);
	radix_sort(stacks_ab, values, is_bench);
	if (is_adpt)
		do_print(values, is_bench, "Adaptive / O(n log n)");
	else
		do_print(values, is_bench, "Complex / O(n log n");
	return (0);
}

int	do_adaptive(char **argv, t_stack *stacks_ab, int is_bench, int *flag_find)
{
	float	disorder_value;

	if (flag_find[0] == 0 && flag_find[1] == 0)
	{
		if (!ft_parse(argv, stacks_ab, 0, 0))
			return (0);
	}
	else if (is_bench && (flag_find[1] == 5 || flag_find[0] == 5))
	{
		if (!ft_parse(argv, stacks_ab, 1, 1))
			return (0);
	}
	else if (!ft_parse(argv, stacks_ab, 1, 0))
		return (0);
	disorder_value = disorder(stacks_ab);
	destroy_all(NULL, stacks_ab, 0);
	if (disorder_value <= 0.2f)
		return (do_simple(argv, stacks_ab, is_bench, 0));
	if (disorder_value <= 0.5f)
		return (do_medium(argv, stacks_ab, is_bench, 0));
	else
		return (do_complex(argv, stacks_ab, is_bench, 0));
}

int	flag_validation(int ac, char **argv, t_stack *stacks_ab)
{
	int	flag_find[2];
	int	is_bench;

	is_bench = 0;
	flag_detect(argv, flag_find);
	if (flag_find[0] == -1 || flag_find[1] == -1)
		return (ft_putstr_fd("Error\n", 2), -1);
	if ((ac < 4 && flag_find[0] != 0 && flag_find[1] != 0))
		return (ft_putstr_fd("Error\n", 2), -1);
	if (flag_find[0] == flag_find[1] && flag_find[0] != 0)
		return (ft_putstr_fd("Error\n", 2), -1);
	if (flag_find[0] == 1 || flag_find[1] == 1)
		is_bench = 1;
	if (flag_find[0] == 2 || flag_find[1] == 2)
		return (do_simple(argv, stacks_ab, is_bench, 0));
	if (flag_find[0] == 3 || flag_find[1] == 3)
		return (do_medium(argv, stacks_ab, is_bench, 0));
	if (flag_find[0] == 4 || flag_find[1] == 4)
		return (do_complex(argv, stacks_ab, is_bench, 0));
	else
		return (do_adaptive(argv, stacks_ab, is_bench, flag_find));
}
