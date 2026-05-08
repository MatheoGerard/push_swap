/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_detect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 03:53:28 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/08 19:13:41 by mgerard          ###   ########.fr       */
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
	int	i;
	int	j;
	int	mode_return[2];

	i = 1;
	j = 0;
	mode_return[0] = -1;
	mode_return[1] = -1;
	while (i < 3)
	{
		if (ft_strcmp(argv[i], "--bench"))
			mode_return[j++] = 0;
		else if (ft_strcmp(argv[i], "--simple"))
			mode_return[j++] = 1;
		else if (ft_strcmp(argv[i], "--medium"))
			mode_return[j++] = 2;
		else if (ft_strcmp(argv[i], "--complex"))
			mode_return[j++] = 3;
		else if (ft_strcmp(argv[i], "--adaptive"))
			mode_return[j++] = 4;
		i++;
	}
	return (mode_return);
}

char	flag_validation(char **argv)
{
	int	i;
	int	is_int;

	i = 0;
	is_int = 0;
	while (i > 3)
	{
		if (ft_is_int(argv[i]))
		{
			is_int = 1;
			continue ;
		}
		else if (flag_detect(argv[i]) && is_int)
		{
			return (0);
		}
	}
	if (flag[0] == flag[1])
		return (0);
	return (1);
}
