/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:25:32 by user              #+#    #+#             */
/*   Updated: 2025/06/04 16:46:45 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	validation(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || '9' < str[i])
			return (0);
		i++;
	}
	return (1);
}

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
			display_error("Failed to send message.");
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
	(void)signal;
	return ;
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3 || !validation(argv[1]))
		display_error("Invalid Argument.");
	pid = ex_atoi(argv[1]);
	if (pid <= 0)
		display_error("Invalid Pid.");
	signal(SIGUSR2, signal_handler);
	send_messages(pid, argv[2]);
	return (0);
}
