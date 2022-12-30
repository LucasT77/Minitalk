/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:29:48 by luaraujo          #+#    #+#             */
/*   Updated: 2022/12/30 18:35:07 by luaraujo         ###   ########.fr       */
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
	shift = 0;
	byte = 0 | bit << shift

	
}

int	main(void)
{
	struct sigaction	act;

	ft_putnbr_fd(getpid(), 1);
	act.sa_handler = &handler;

}
