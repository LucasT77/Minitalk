/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:28:55 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/07 13:28:57 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	index_beginning(char const *s1, char const *set)
{
	size_t	index_s1;
	size_t	result;

	if (!s1 || !set)
		return (0);
	index_s1 = 0;
	result = 0;
	while (s1[index_s1] != '\0')
	{
		if (ft_strchr(set, s1[index_s1]) == NULL)
			break ;
		result = index_s1 + 1;
		index_s1++;
	}
	return (result);
}

static size_t	index_end(char const *s1, char const *set)
{
	size_t	index_s1;
	size_t	result;

	if (!s1 || !set)
		return (0);
	index_s1 = ft_strlen(s1);
	if (index_s1 > 0)
		index_s1 = index_s1 - 1;
	result = index_s1;
	while (index_s1 != 0)
	{
		if (ft_strchr(set, s1[index_s1]) == NULL)
			break ;
		result = index_s1 - 1;
		index_s1--;
	}
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	i_end;
	size_t	i_new;
	char	*newstr;

	if (!s1 || !set)
		return (0);
	i = index_beginning(s1, set);
	i_end = index_end(s1, set);
	if (i > i_end)
	{
		newstr = malloc(sizeof(char));
		newstr[0] = '\0';
		return (newstr);
	}
	i_new = 0;
	newstr = malloc(sizeof(char const) * (i_end - i + 2));
	if (!newstr)
		return (NULL);
	while (i <= i_end)
		newstr[i_new++] = s1[i++];
	newstr[i_new] = '\0';
	return (newstr);
}

/*
A funcao checa o primeiro caracter de s1, 
se esse caracter aparecer em qualquer lugar de set, ester caracter e eliminado.
Se sim, a funcao continua checando o resto dos caracteres 
ate que haja um que nao aparece em set.
A funcao entao para de eliminar os primeiros caracteres.
Tudo isso tambem ocorre do ultimo caracter em diante.
Se por exeplo o primeiro e ultimo caracter nao aparecem em lugar algum de set,
entao nada e eliminado. 
*/