/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:06:52 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/07 13:06:54 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*bigstr;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	bigstr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!bigstr)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		bigstr[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		bigstr[i] = s2[i - len1];
		i++;
	}
	bigstr[i] = '\0';
	return (bigstr);
}
