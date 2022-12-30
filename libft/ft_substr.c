/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:45:14 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/07 12:45:16 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_s;
	size_t			i;
	unsigned int	cont;

	if (!s)
		return (0);
	sub_s = malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (0);
	if (start >= ft_strlen(s))
	{
		ft_bzero(sub_s, len);
		return (sub_s);
	}
	i = 0;
	cont = start;
	while (i < len && s[cont] != '\0')
		sub_s[i++] = s[cont++];
	sub_s[i] = '\0';
	if (cont - i == start)
		return (sub_s);
	else
		return (0);
}
