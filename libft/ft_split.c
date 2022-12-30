/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:04:41 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/07 18:04:44 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy_words(char const *src, int len)
{
	int		i;
	char	*dest_aux;
	char	*src_aux;
	char	*dest;

	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	i = 0;
	dest_aux = (char *)dest;
	src_aux = (char *)src;
	while (i < len)
	{
		dest_aux[i] = src_aux[i];
		i++;
	}
	dest_aux[i] = '\0';
	return (dest);
}

static int	num_of_words(char const *s, char c)
{
	int	i;
	int	words;
	int	new;

	i = 0;
	new = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
			new = 1;
		if (s[i] != c && (new == 1 || i == 0))
		{
			words++;
			new = 0;
		}
		i++;
	}
	return (words);
}

static char	**ft_split_aux(char const *s, char c, int words, char **str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		while (s[len] != c && s[len] != '\0')
			len++;
		if (len > 0)
		{
			str[i] = copy_words(s, len);
			s += len;
			len = 0;
		}
		i++;
	}
	str[words] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;

	if (!s)
		return (0);
	words = num_of_words(s, c);
	str = malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (0);
	str = ft_split_aux(s, c, words, str);
	return (str);
}
