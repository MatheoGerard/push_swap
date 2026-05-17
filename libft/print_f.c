/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:45:07 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/17 16:19:28 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(char c)
{
	write(1, &c, 1);
	return (1);
}

void	give(char keys[])
{
	keys[0] = 'c';
	keys[1] = 's';
	keys[2] = 'p';
	keys[3] = 'd';
	keys[4] = 'i';
	keys[5] = 'u';
	keys[6] = 'x';
	keys[7] = 'X';
	keys[8] = '%';
	keys[9] = 'f';
}

int	format_print(char c, va_list args)
{
	int		(*f[10])(va_list);
	int		i;
	char	keys[10];

	i = 0;
	give(keys);
	f[0] = &ft_putchar;
	f[1] = &ft_putstr;
	f[2] = &ft_put_p;
	f[3] = &ft_putnbr;
	f[4] = &ft_putnbr;
	f[5] = &ft_put_u;
	f[6] = &ft_puthexa;
	f[7] = &ft_puthexa_big;
	f[8] = &ft_putpercent;
	f[9] = &ft_putfloat;
	while (i < 10 && keys[i] != c)
		i++;
	if (i == 10)
		return (-1);
	return ((f[i])(args));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			len = format_print(*str, args);
			if (len == -1)
				i += (ft_putchr('%') + ft_putchr(*str));
			else
				i += len;
		}
		else
			i += ft_putchr(*str);
		str++;
	}
	va_end(args);
	return (i);
}

/*#include <stdio.h>
#include <limits.h>

int	main(void)
{
	//printf("len is :%d\n", ft_printf("%u\n", (unsigned int)INT_MAX *2 + 1));
	//printf("len is :%d\n", printf("%u\n", (unsigned int)INT_MAX *2 + 1));
	//printf("printf len is :%d\n", printf("%%\nhello\n%c
	//\n%p\n%x\n%s\n", 'c', &ft_printf, 136354));
	ft_printf("%d\n", ft_printf("%% %%"));
	ft_printf("%d\n", printf("%% %%"));
}*/
