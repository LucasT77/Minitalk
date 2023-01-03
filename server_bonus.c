/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:28:12 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/03 16:22:25 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	handler(int signum, siginfo_t *info, void *ucontext)
{
	static unsigned char	byte;
	static int				shift;
	int						bit;

	(void)ucontext;
	if (signum == SIGUSR1)
		bit = 1;
	if (signum == SIGUSR2)
		bit = 0;
	byte = byte | bit << shift;
	shift++;
	if (shift == 8)
	{
		if (byte == '\0')
		{
			usleep(100);
			kill(info->si_pid, SIGUSR1);
		}
		else
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
	act.sa_sigaction = &handler;
	act.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
}
