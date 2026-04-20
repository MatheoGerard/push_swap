/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:21:38 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/20 18:53:38 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_int(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	**ft_parse(char **str_array)
{
	unsigned int	i;
	int			*stack_a;
	int			*stack_a;
	int			**stacks_ab;

	i = 0;
	while (str_array[i])
		if (!ft_is_int(str_array[i++]))
			return (NULL);
	stack_a = (int *)malloc((i + 1) * sizeof(int));
	stack_b = (int *)ft_calloc(i + 1, sizeof(int));
	if (stack_a == NULL)
		return (NULL);
	i = 0;
	while (str_array[i])
	{
		stack_a[i] = ft_atoi(str_array[i]);
		i++;
	}
	stack_a[i] = '\0';
	stacks_ab[0] = stack_a;
	stacks_ab[1] = stack_b;
	return (stacks_ab);
}
