/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_detect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 03:53:28 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/16 22:51:03 by nlovius          ###   ########.fr       */
/*   Updated: 2026/05/15 16:39:39 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *argv, char *flag)
{
	int	i;

	if (argv == NULL)
		return (0);
	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] != flag[i])
			return (0);
		i++;
	}
	return (1);
}

void	flag_detect(char **argv, int mode_return[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	mode_return[0] = -1;
	mode_return[1] = -1;
	if (!argv[i])
		return ;
	while (i < 3)
	{
		if (ft_is_int(argv[i]))
			mode_return[j++] = 0;
		else if (ft_strcmp(argv[i], "--bench"))
			mode_return[j++] = 1;
		else if (ft_strcmp(argv[i], "--simple"))
			mode_return[j++] = 2;
		else if (ft_strcmp(argv[i], "--medium"))
			mode_return[j++] = 3;
		else if (ft_strcmp(argv[i], "--complex"))
			mode_return[j++] = 4;
		else if (ft_strcmp(argv[i], "--adaptive"))
			mode_return[j++] = 5;
		else if (argv[i] == NULL)
			mode_return[j++] = -2;
		i++;
	}
}

void	*init_values(t_stack *stacks_ab, t_op_count *values)
{
	values->in_stack = 'a';
	values->disorder_val = disorder(stacks_ab);
	values->pa = 0;
	values->pb = 0;
	values->ra = 0;
	values->rb = 0;
	values->rr = 0;
	values->rra = 0;
	values->rrb = 0;
	values->rrr = 0;
	values->sa = 0;
	values->sb = 0;
	values->ss = 0;
	return (values);
}

int	do_simple(char** argv, t_stack *stacks_ab, int is_bench, int is_adpt)
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

int	do_medium(char** argv, t_stack *stacks_ab, int is_bench, int is_adpt)
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

int	do_complex(char** argv, t_stack *stacks_ab, int is_bench, int is_adpt)
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
		ft_parse(argv, stacks_ab, 0, 0);
	else if (is_bench && (flag_find[1] == 5 || flag_find[0] == 5))
		ft_parse(argv, stacks_ab, 1, 1);
	else
		ft_parse(argv, stacks_ab, 1, 0);
	disorder_value = disorder(stacks_ab);
	if (disorder_value <= .2f)
		return (do_simple(argv, stacks_ab, is_bench, 1));
	else if (disorder_value <= .5f)
		return (do_medium(argv, stacks_ab, is_bench, 1));
	else
		return (do_complex(argv, stacks_ab, is_bench, 1));
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
	return (0);
}






