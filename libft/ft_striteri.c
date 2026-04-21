/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:14:23 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/17 13:55:51 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i])
	{
		f((unsigned int)i, &s[i]);
		i++;
	}
}

/*#include <stdio.h>

void    my_test_callback(unsigned int i, char *c)
{
        if (i % 2 == 0 && (*c >= 'a' && *c <= 'z'))
                *c -= 32;
}

int     main(void)
{
        char    str[] = "dlrow olleh";

        printf("Original string: %s\n", str);
        ft_striteri(str, my_test_callback);
        printf("Mapped string:   %s\n", str);
}*/
