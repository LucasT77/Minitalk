/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:29:48 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/02 18:12:16 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	handler(int signum)
{
	static unsigned char	byte;
	static int				shift;
	int						bit;

	if (signum == SIGUSR1)
		bit = 1;
	if (signum == SIGUSR2)
		bit = 0;
	byte = byte | bit << shift;
	shift++;
	if (shift == 8)
	{
		write(1, &byte, 1);
		byte = 0;
		shift = 0;
	}
	usleep(0);
}

int	main(void)
{
	struct sigaction	act;

	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	act.sa_handler = &handler;
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
}
