/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:28:44 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/29 16:31:41 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(va_list args, char a_or_big_a)
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
		write(1, &str[i++], 1);
	return ((int)nb);
}

int	ft_puthexa(va_list args)
{
	return (ft_puthex(args, 'a'));
}

int	ft_puthexa_big(va_list args)
{
	return (ft_puthex(args, 'A'));
}

int	ft_put_pointer(unsigned long nb)
{
	unsigned long	mod;
	unsigned int	i;
	char			str[17];

	write(1, &"0x", 2);
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
		write(1, &str[i++], 1);
	return ((int)nb);
}

int	ft_put_p(va_list args)
{
	intptr_t	nb;

	nb = (unsigned long)va_arg(args, void *);
	if (nb == 0)
	{
		write(1, &"(nil)", 5);
		return (5);
	}
	return (ft_put_pointer(nb));
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
