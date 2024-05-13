/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:44:52 by mgreshne          #+#    #+#             */
/*   Updated: 2024/04/14 17:04:43 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	end_message(unsigned int pid)
{
	write(1, "\n", 1);
	kill(pid, SIGUSR2);
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static char				current_char = 0;
	static int				bit_count = 0;
	char					bit;
	static unsigned int		pid;

	(void)context;
	if (signum == SIGUSR1)
		bit = '1';
	else
		bit = '0';
	current_char |= (bit - '0') << bit_count;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &current_char, 1);
		if (current_char == '\0')
			end_message(pid);
		current_char = 0;
		bit_count = 0;
	}
	if (info->si_pid != 0)
		pid = info->si_pid;
	kill(pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Welcome to Server. My server PID: %d\n", getpid());
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
