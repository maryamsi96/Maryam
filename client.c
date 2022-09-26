/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaleh <msaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:53:46 by msaleh            #+#    #+#             */
/*   Updated: 2022/09/26 18:53:48 by msaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_confirm(int signal)
{
	// signal == SIGUSR1;
	if (signal == SIGUSR1)
		ft_printf("error\n");
	else
		ft_printf("signal recieved succefully\n");
}

void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = -1;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][++i] != '\0')
		{
			signal(SIGUSR1, ft_confirm);
			signal(SIGUSR2, ft_confirm);
			ft_send_bits(pid, argv[2][i]);
		}
		ft_send_bits(pid, '\n');
	}
	else
	{
		ft_printf("Error: wrong format.\n");
		ft_printf("Try: ./client_bonus [PID] [MESSAGE]\n");
		return (1);
	}
	return (0);
}
