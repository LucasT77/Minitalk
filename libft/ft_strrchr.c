/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:49:54 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/05 16:50:06 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	i = length - 1;
	while (i >= 0)
	{
		if (s[i] == c)
		{
			return ((char *)s + i);
			break ;
		}
		i--;
	}
	if (s[length] == '\0' && c == '\0')
		return ((char *)s + length);
	else
		return (NULL);
}
