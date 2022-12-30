/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:11:46 by luaraujo          #+#    #+#             */
/*   Updated: 2022/08/26 15:11:48 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	length_dst;
	size_t	length_src;

	length_src = ft_strlen(src);
	if (size <= 0)
		return (length_src);
	length_dst = ft_strlen(dst);
	if (length_dst >= size)
		return (size + length_src);
	i = 0;
	x = length_dst;
	if (length_dst < size - 1 && size > 0)
	{
		while (src[i] != '\0' && i < size - length_dst - 1)
		{
			dst[x] = src[i];
			x++;
			i++;
		}
		dst[x] = '\0';
	}
	return (length_dst + length_src);
}
