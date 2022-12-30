/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:22:48 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/05 14:22:50 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (0);
	d = dest;
	s = src;
	if (d < s)
	{
		while ((int)n != 0)
		{
			*d++ = *s++;
			n--;
		}
	}
	else
	{
		while ((int)n != 0)
		{
			*(d + (n - 1)) = *(s + (n - 1));
			n--;
		}
	}
	return (dest);
}
