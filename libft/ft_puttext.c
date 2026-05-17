/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:18:25 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/29 16:28:02 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(va_list args)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(va_list args)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(args, char *);
	if (s == 0)
	{
		write(1, &"(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putpercent(va_list args)
{
	(void)args;
	write(1, &"%", 1);
	return (1);
}
