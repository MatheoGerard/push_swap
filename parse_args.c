/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:21:38 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/14 21:18:04 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_int(char *str)
{
	if (!str)
		return (0);
	if (*str == '0' && ft_strlen(str) != 1)
		return (0);
	if (*str == '-')
	{
		if (ft_strlen(str) == 1 || str[1] == '0')
			return (0);
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

t_stack	*ft_init(char **str_array, t_stack *stacks_ab)
{
	int	i;

	i = 0;
	while (str_array[i])
		if (!ft_is_int(str_array[i++]))
		{
			stacks_ab = NULL;
			return (stacks_ab);
		}
	stacks_ab[0].nbrs = (int *)malloc(i * sizeof(int));
	stacks_ab[1].nbrs = (int *)malloc(i * sizeof(int));
	stacks_ab[0].index = (int *)malloc(i * sizeof(int));
	stacks_ab[1].index = (int *)malloc(i * sizeof(int));
	if (stacks_ab[0].nbrs == NULL || stacks_ab[1].nbrs == NULL)
		return (NULL);
	stacks_ab[0].current_len = i;
	stacks_ab[1].current_len = 0;
	return (stacks_ab);
}

char	**to_join_to_split(char **av)
{
	int	i;
	char	*av_join;
	char	*tmp;
	char	*tmp_space_av;
	char	**av_split;

	i = 0;
	av_join = ft_strdup(av[i]);
	while (av[i + 1])
	{
		tmp_space_av = ft_strjoin(" ", av[++i]);
		tmp = ft_strjoin(av_join, tmp_space_av);
		free(tmp_space_av);
		free(av_join);
		av_join = tmp;
	}
	av_split = ft_split(av_join, ' ');
	free(av_join);
	return (av_split);
}

int	ft_parse(char **argv, t_stack *stacks_ab, int is_flag, int is_bench)
{
	int	i;

	if (is_flag)
		argv++;
	if (is_bench)
		argv++;
	i = 0;
	argv++;
	stacks_ab = ft_init(argv, stacks_ab);
	if (!stacks_ab)
		return (ft_putstr_fd("Error\n", 2), 0);
	while (argv[i])
	{
		stacks_ab[0].nbrs[i] = ft_atoi(argv[i]);
		stacks_ab[0].index[i] = i;
		i++;
	}
	if (is_double_num(stacks_ab, NULL))
		return (ft_putstr_fd("Error\n", 2), 0);
	return (1);
}
