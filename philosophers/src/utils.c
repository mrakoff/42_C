/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:46:31 by msalangi          #+#    #+#             */
/*   Updated: 2025/09/06 20:02:45 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print(t_philo *philo, t_data *data, char *status)
{
	lock(&data->print_mutex);
	if (!status)
	{
		printf("%s%s%s", GREEN, FULL, END);
		unlock(&data->print_mutex);
		return ;
	}
	lock(&data->dead_mutex);
	if (!data->stop)
		printf("%lu %s%i%s %s", get_time() - (data->start_time),
			GREEN, philo->index + 1, END, status);
	unlock(&data->dead_mutex);
	unlock(&data->print_mutex);
}

unsigned long	get_time(void)
{
	unsigned long	time;
	struct timeval	t;

	gettimeofday(&t, NULL);
	time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	return (time);
}

long	atoui(const char *str)
{
	long	num;

	num = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

static int	is_num(char *s)
{
	while (*s >= '0' && *s <= '9')
		s++;
	if (*s == '\0')
		return (1);
	return (0);
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (1);
	while (i < argc && is_num(argv[i]))
		i++;
	if (i != argc || argv[1][0] == '0' || argv[2][0] == '0')
		return (1);
	if (argc == 6 && (argv[5][0] == '\0' || argv[5][0] == '0'))
		return (1);
	return (0);
}
