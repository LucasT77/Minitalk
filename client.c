/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:29:22 by luaraujo          #+#    #+#             */
/*   Updated: 2022/12/30 16:31:44 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

send_signals(int pid, unsigned char *str)
{
	int	i;
	int	shift;

	i = 0;
	shift = 0;
	while (str[i])
	{
		while (shift < 8)
		{
			if (1 << shift & str[i]) //EXAMPLE: A = 0100 0001; 0000 0001 & A = 0000 0001 (true); 0000 0010 & A = 0000 0000 (false)
				kill(pid, SIGUSR1); // SIGUSR1 = 1
			else
				kill(pid, SIGUSR2); // SIGUSR2 = 0
			shift++;
		}
		shift = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*str;
	struct sigaction	act;
	
	if (argc != 3)
		ft_putstr_fd("Invalid number of arguments", 1);
	else
	{
		send_signals(argv[1], argv[2]);
	}
	
}
