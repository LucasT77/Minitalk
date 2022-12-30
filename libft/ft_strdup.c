/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:28:01 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/07 12:28:04 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*stdup;

	i = ft_strlen(s) + 1;
	stdup = malloc(sizeof(char) * i);
	if (!stdup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		stdup[i] = s[i];
		i++;
	}
	stdup[i] = '\0';
	return (stdup);
}
