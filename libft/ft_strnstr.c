/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:31:09 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/06 13:31:12 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	if (!*little || (len == 0 && !*little))
		return ((char *)big);
	if (len == 0)
		return (0);
	i = 0;
	n = 0;
	while (big[i] != '\0')
	{
		while (big[i + n] == little[n] && little[n] && (i + n) < len)
			n++;
		if (little[n] == '\0')
			break ;
		n = 0;
		i++;
	}
	if ((i - 1 == len || big[i] == '\0') && n == 0)
		return (NULL);
	else
		return ((char *)big + i);
}
