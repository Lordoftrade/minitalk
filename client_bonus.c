/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:44:36 by mgreshne          #+#    #+#             */
/*   Updated: 2024/04/14 17:04:39 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

static int	g_sig;

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr == '0')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * res);
}

void	ft_error(int i)
{
	if (i == 1)
		ft_printf("Error! Use: ./client_bonus <<server_pid>> <<message>>\n");
	if (i == 2)
		ft_printf("Invalid server PID\n");
	if (i == 3)
		ft_printf("Mistake! The message is empty!");
	exit(EXIT_FAILURE);
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		g_sig = 1;
	}
	else
		write(1, "The message has been received and displayed!\n", 45);
}

void	ft_send_message(pid_t server_pid, char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		g_sig = 0;
		if ((1 << i) & c)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (g_sig != 1)
			;
	}
}

int	main(int argc, char **argv)
{
	const char	*message;
	pid_t		server_pid;
	int			i;

	i = 0;
	if (argc != 3)
		ft_error(1);
	else
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0 || !(kill(server_pid, 0) == 0))
			ft_error(2);
		message = argv[2];
		if (!message || message[i] == '\0')
			ft_error(3);
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		while (message[i])
			ft_send_message(server_pid, message[i++]);
		ft_send_message(server_pid, '\0');
	}
	write(1, "The message has been sent!\n", 27);
	return (0);
}
