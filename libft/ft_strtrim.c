/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:23:46 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/16 12:49:14 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_contains(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set && set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	int		i;
	int		j;
	int		trimmed_len;
	char	*trim;

	i = 0;
	j = 0;
	if (s)
		j = (int)ft_strlen(s);
	while (s && s[i] && set_contains(s[i], set))
		i++;
	while (s && i != j && set_contains(s[j - 1], set))
		j--;
	trimmed_len = j - i;
	trim = (char *)malloc((trimmed_len + 1) * sizeof(char));
	if (trim == NULL)
		return (trim);
	j = 0;
	while (j < trimmed_len)
	{
		trim[j] = s[i + j];
		j++;
	}
	trim[j] = 0;
	return (trim);
}

/*#include <stdio.h>

int	main(void)
{
	char	*trimmed0 = ft_strtrim(NULL, NULL);
	char	*trimmed1 = ft_strtrim("!&%@$@!TRIM MEEE!?!!!@!#", "!@&#$%");
	printf("%p\n", trimmed0);
	printf("%s\n", trimmed0);
	printf("%s\n", trimmed1);
	free(trimmed0);
	free(trimmed1);
}*/
