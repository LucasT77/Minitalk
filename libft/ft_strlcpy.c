/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:23:49 by luaraujo          #+#    #+#             */
/*   Updated: 2022/08/24 18:23:51 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	length;

	n = 0;
	length = 0;
	while (src[length])
		length++;
	if (size > 0)
	{
		while (src[n] != '\0' && n < (size - 1))
		{
			dst[n] = src[n];
			n++;
		}
		dst[n] = '\0';
	}
	return (length);
}
