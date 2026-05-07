/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_detect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 03:53:28 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/07 04:14:29 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *argv, char *flag)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] != flag[i])
			return (0);
		i++;
	}
	return (1);
}

int	flag_detect(char **argv)
{
	if (ft_strcmp(argv[1], "--simple"))
		return (0);
	else if (ft_strcmp(argv[1], "--medium"))
		return (1);
	else if (ft_strcmp(argv[1], "--complex"))
		return (2);
	else if (ft_strcmp(argv[1], "--adaptive"))
		return (3);
	else
		return (4);
}
