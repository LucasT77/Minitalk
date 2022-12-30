/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:13:16 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/08 17:13:26 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(long int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	n2;

	n2 = n;
	len = intlen(n2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n2 < 0)
	{
		str[0] = '-';
		n2 *= -1;
	}
	str[len] = '\0';
	if (n2 == 0)
		str[len - 1] = '0';
	while ((len > 0 || str[len] != '-') && n2 != 0)
	{
		str[len - 1] = n2 % 10 + '0';
		n2 /= 10;
		len--;
	}
	return (str);
}
