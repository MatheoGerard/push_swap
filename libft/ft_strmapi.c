/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:54:40 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/16 13:11:36 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	size_t	len;
	char	*mapped;

	i = 0;
	len = 0;
	if (s)
		len = ft_strlen(s);
	mapped = (char *)malloc((len + 1) * sizeof (char));
	if (mapped == NULL)
		return (mapped);
	while (s && s[i])
	{
		mapped[i] = f((unsigned int)i, s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}

/*#include <stdio.h>

char	my_test_callback(unsigned int i, char c)
{
	if (i % 2 == 0 && (c >= 'a' && c <= 'z'))
		return (c - 32);
	return (c);
}

int	main(void)
{
	char	*str = "foo bar baz";
	char	*result;

	printf("Original string: %s\n", str);
	result = ft_strmapi(str, my_test_callback);
	if (result)
	{
		printf("Mapped string:   %s\n", result);
		free(result);
	}
	else
		printf("Allocation failed or input was NULL.\n");
}*/
