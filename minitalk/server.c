/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:02:31 by msalangi          #+#    #+#             */
/*   Updated: 2025/06/09 20:05:38 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*g_received_string;

void	ft_print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID is %d\n", pid);
}

void	ft_count_alloc(char len[], int *i, int *flag, char byte)
{
	len[(*flag)++] = byte;
	if (*flag == 10)
	{
		*i = ft_atoi(len);
		g_received_string = malloc(sizeof(char) * *i + 1);
		if (!g_received_string)
			return ;
		g_received_string[*i] = '\0';
		*i = 0;
	}
}

void	ft_receive_signal(int signum)
{
	static struct s_byte	b;
	static char				len[11];
	static int				flag;
	static int				i;

	if (signum == SIGUSR1)
		b.received_bits[b.ind++] = '0';
	else if (signum == SIGUSR2)
		b.received_bits[b.ind++] = '1';
	if (b.ind == 8)
	{
		b.byte = ft_binary_to_decimal(b.received_bits);
		if (flag < 10)
			ft_count_alloc(len, &i, &flag, b.byte);
		else
			g_received_string[i++] = b.byte;
		if (b.byte == '\0')
		{
			flag = 0;
			ft_printf("%s\n", g_received_string);
			free(g_received_string);
		}
		b.ind = 0;
	}
}

int	main(void)
{
	ft_print_pid();
	signal(SIGUSR1, ft_receive_signal);
	signal(SIGUSR2, ft_receive_signal);
	while (1)
		pause();
	return (0);
}
