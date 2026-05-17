/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:36:51 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/29 16:16:01 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u(va_list args)
{
	unsigned int	i;
	unsigned int	n;
	char			str[12];

	n = va_arg(args, unsigned int);
	i = 10;
	str[11] = '\0';
	while (n > 9)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	str[i] = (n % 10) + '0';
	n = 10 - i + 1;
	while (str[i])
		write(1, &str[i++], 1);
	return (n);
}

int	ft_putnbr(va_list args)
{
	int				nb;
	unsigned int	i;
	unsigned int	n;
	char			str[12];

	nb = va_arg(args, int);
	n = (unsigned int)nb;
	i = 10;
	str[11] = '\0';
	if (nb < 0)
	{
		n = (unsigned int)-nb;
		write(1, &"-", 1);
	}
	while (n > 9)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	str[i] = (n % 10) + '0';
	nb = 10 - i + (nb < 0) + 1;
	while (str[i])
		write(1, &str[i++], 1);
	return (nb);
}

/*void	test(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	ft_putnbr(args);
	write(1, &"\n", 1);
	ft_put_u(args);
	va_end(args);
}

#include <limits.h>

int	main(void)
{
	int	nb;
	unsigned int zu;

	nb = INT_MAX;
	zu = ((unsigned int)nb) *2 + 1;
	test("",nb, zu);
}*/
