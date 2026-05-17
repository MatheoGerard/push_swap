/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:18:25 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/17 16:47:35 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int fd, va_list args)
{
	char	c;

	c = va_arg(args, int);
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr(int fd, va_list args)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(args, char *);
	if (s == 0)
	{
		write(fd, &"(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putpercent(int fd, va_list args)
{
	(void)args;
	write(fd, &"%", 1);
	return (1);
}
