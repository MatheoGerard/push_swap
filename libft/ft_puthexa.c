/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:28:44 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/17 16:50:06 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(int fd, va_list args, char a_or_big_a)
{
	unsigned int	i;
	unsigned int	nb;
	unsigned int	mod;
	char			str[9];

	nb = va_arg(args, unsigned int);
	i = 7;
	str[8] = '\0';
	while (1)
	{
		mod = nb % 16;
		if (mod < 10)
			str[i] = mod + '0';
		else
			str[i] = (mod - 10) + a_or_big_a;
		if (nb < 16)
			break ;
		nb /= 16;
		i--;
	}
	nb = (7 - i) + 1;
	while (str[i])
		write(fd, &str[i++], 1);
	return ((int)nb);
}

int	ft_puthexa(int fd, va_list args)
{
	return (ft_puthex(fd, args, 'a'));
}

int	ft_puthexa_big(int fd, va_list args)
{
	return (ft_puthex(fd, args, 'A'));
}

int	ft_put_pointer(int fd, unsigned long nb)
{
	unsigned long	mod;
	unsigned int	i;
	char			str[17];

	write(fd, &"0x", 2);
	i = 15;
	str[16] = '\0';
	while (1)
	{
		mod = nb % 16;
		if (mod < 10)
			str[i] = mod + '0';
		else
			str[i] = (mod - 10) + 'a';
		if (nb < 16)
			break ;
		nb /= 16;
		i--;
	}
	nb = (15 - i) + 2 + 1;
	while (str[i])
		write(fd, &str[i++], 1);
	return ((int)nb);
}

int	ft_put_p(int fd, va_list args)
{
	intptr_t	nb;

	nb = (unsigned long)va_arg(args, void *);
	if (nb == 0)
	{
		write(fd, &"(nil)", 5);
		return (5);
	}
	return (ft_put_pointer(fd, nb));
}

/*void  test(const char *str, ...)
{
        va_list args;

        va_start(args, str);
        ft_puthexa(args);
        write(1, &"\n", 1);
        ft_puthexa_big(args);
        write(1, &"\n", 1);
        ft_put_p(args);
        write(1, &"\n", 1);
        ft_put_p(args);
        write(1, &"\n", 1);
        va_end(args);
}

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int     main(void)
{
        unsigned int nb;
        unsigned int zu;
	int	*ptr;
	char	*s1;
	char	*s2;

        nb = 456;
        zu = ((unsigned int)INT_MAX) * 2 + 1;
        test("this is obv a test duhh",zu, zu, s2, NULL);
	printf("%p\n%p\n", s2, NULL);
}*/
