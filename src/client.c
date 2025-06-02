/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:25:32 by user              #+#    #+#             */
/*   Updated: 2025/06/02 17:14:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	send_bit(pid_t pid, unsigned char message)
{
	int	i;
	int	signal;

	i = 7;
	while (i >= 0)
	{
		if ((message >> i) & 1)
			signal = SIGUSR2;
		else
			signal = SIGUSR1;
		if (kill(pid, signal) == -1)
		{
			ft_printf("Failure!\n");
			exit(EXIT_FAILURE);
		}
		usleep(WAIT_TIME);
		i--;
	}
	return ;
}

void	send_messages(pid_t pid, char *message)
{
	while (*message)
	{
		send_bit(pid, *message);
		message++;
	}
	send_bit(pid, '\n');
	return ;
}

void	signal_handler(int signal)
{
	ft_printf("Success.");
	(void)signal;
	return ;
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
		return (-1);
	pid = ex_atoi(argv[1]);
	if (pid <= 0)
		return (-1);
	signal(SIGUSR2, signal_handler);
	send_messages(pid, argv[2]);
	return (0);
}
