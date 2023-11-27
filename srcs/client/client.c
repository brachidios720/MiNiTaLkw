/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:49:29 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/11/09 19:38:52 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_send_signal(int pid, char c)
{
	int	n;
	int	i;

	n = c;
	i = 0;
	while (i < 8)
	{
		if ((n & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50);
		n >>= 1;
		++i;
	}
	return ;
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(1, "Args error", 10);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_send_signal(pid, argv[2][i]);
			i++;
		}
		ft_send_signal(pid, '\0');
	}
	return (0);
}
