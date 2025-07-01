/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:15:04 by msalangi          #+#    #+#             */
/*   Updated: 2025/06/09 21:28:32 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_byte(pid_t server_pid, int letter)
{
	int		ind;
	char	*byte;

	ind = 0;
	byte = ft_decimal_to_binary(letter);
	while (byte[ind])
	{
		if (byte[ind] == '0')
			if (kill(server_pid, SIGUSR1) != 0)
				return (write(2, "Signal failed!\n", 15), 1);
		if (byte[ind] == '1')
			if (kill(server_pid, SIGUSR2) != 0)
				return (write(2, "Signal failed!\n", 15), 1);
		usleep(150);
		ind++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		ind;
	char	*len;
	pid_t	server_pid;

	ind = 0;
	if (argc != 3)
		return (write(2, "Format not valid\n", 17), 1);
	server_pid = ft_atoi(argv[1]);
	if (server_pid == -1)
		return (write(2, "Not a valid PID\n", 16), 1);
	len = ft_itoa(ft_strlen(argv[2]));
	while (len[ind])
	{
		send_byte(server_pid, len[ind++]);
		usleep(300);
	}
	ind = 0;
	while (argv[2][ind])
	{
		send_byte(server_pid, argv[2][ind++]);
		usleep(300);
	}
	return (send_byte(server_pid, '\0'), 0);
}
