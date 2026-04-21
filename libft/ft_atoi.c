/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:39:59 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/21 16:33:14 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long int	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		sign = ',' - *nptr;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		nb = nb * 10 + (*nptr - '0');
		if (nb > nb * 10 + *nptr - '0' && sign == 1)
			return ((int)LONG_MAX);
		else if (nb > nb * 10 + *nptr - '0')
			return ((int)LONG_MIN);
		nptr++;
	}
	return (nb * sign);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi("   6549833444"));
	printf("%d\n", atoi("   6549833444"));
	printf("%d\n", ft_atoi("   -654987546654111111111111111111111111111111"));
	printf("%d\n", atoi("   -654987546651111111111111111111111111111111111"));
}*/
