/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:59:52 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/17 13:52:34 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*dup_from_nmemb_start_to_sep(char const *s, char c, int *nstart)
{
	int		len;
	int		i;
	char	*duped;

	len = 0;
	i = 0;
	while (s && s[*nstart] && s[*nstart] == c)
		(*nstart)++;
	while (s && s[*nstart + len] && s[*nstart + len] != c)
		len++;
	duped = (char *)malloc((len + 1) * sizeof(char));
	if (duped == NULL)
		return (duped);
	while (i < len)
	{
		duped[i] = s[*nstart];
		i++;
		(*nstart)++;
	}
	duped[i] = '\0';
	return (duped);
}

static int	count_nmemb(char const *s, char c)
{
	int	i;
	int	nmemb;
	int	is_sep;

	i = 0;
	nmemb = 0;
	is_sep = 1;
	while (s && s[i])
	{
		if (s[i] == c)
			is_sep = 1;
		if (is_sep && s[i] != c)
		{
			is_sep = 0;
			nmemb++;
		}
		i++;
	}
	return (nmemb);
}

static void	free_all(char **str_array)
{
	int	n;

	n = 0;
	while (str_array[n] != NULL)
	{
		free(str_array[n]);
		n++;
	}
	free(str_array);
}

char	**ft_split(char const *s, char c)
{
	int		nmemb;
	int		n;
	int		i[1];
	char	**splitted;

	n = 0;
	*i = 0;
	nmemb = count_nmemb(s, c);
	splitted = (char **)malloc((nmemb + 1) * sizeof (char *));
	if (splitted == NULL)
		return (splitted);
	while (n < nmemb)
	{
		splitted[n] = dup_from_nmemb_start_to_sep(s, c, i);
		if (splitted[n] == NULL)
		{
			free_all(splitted);
			return (NULL);
		}
		n++;
	}
	splitted[n] = NULL;
	return (splitted);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char **test0 = ft_split("Hello this is first test", ' ');
	char **test1 = ft_split("    Hello  this is second test  ", ' ');
	int	i;

	i = 0;
	while (test0[i])
	{
		printf("%s\n", test0[i]);
		i++;
	}
	i = 0;
	while (test1[i])
	{
		printf("%s\n", test1[i]);
		i++;
	}
	free_all(test0);
	free_all(test1);
}*/
