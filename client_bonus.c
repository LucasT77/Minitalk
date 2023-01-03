/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:27:59 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/03 17:45:29 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	send_signals(int pid, unsigned char *str)
{
	int	i;
	int	shift;
	int	len;

	i = 0;
	shift = 0;
	len = ft_strlen((char *)str);
	while (i <= len)
	{
		while (shift < 8)
		{
			if (1 << shift & str[i])
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			shift++;
		}
		shift = 0;
		i++;
	}
}

void	handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)signum;
	(void)info;
	(void)ucontext;
	write (1, "Input received.\n", 16);
	exit(0);
}

int	main(int argc, char **argv)
{
	int							pid;
	unsigned char				*str;
	struct sigaction			act;

	if (argc != 3)
	{
		ft_putstr_fd("Invalid number of arguments", 1);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	str = (unsigned char *)argv[2];
	send_signals(pid, str);
	act.sa_sigaction = &handler;
	sigaction(SIGUSR1, &act, NULL);
	sleep(2);
	return (0);
}
