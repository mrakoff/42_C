/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel <mel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:03:11 by msalangi          #+#    #+#             */
/*   Updated: 2025/08/13 15:12:45 by mel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	forks_init(pthread_mutex_t *forks, t_philo *philo, unsigned int i)
{
	if (!philo->index % 2)
	{
		philo->rfork = &forks[i];
		philo->lfork = &forks[(i + 1) % philo->data->philo_count];
	}
	else
	{
		philo->lfork = &forks[i];
		philo->rfork = &forks[(i + 1) % philo->data->philo_count];
	}
}

static void	philo_init(t_data *data, unsigned int philo_count)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (j < philo_count)
	{
		pthread_mutex_init(&data->forks[j], NULL);
		j++;
	}
	while (i < philo_count)
	{
		data->philos[i].index = i;
		data->philos[i].data = data;
		data->philos[i].meal_count = 0;
		forks_init(data->forks, &(data->philos[i]), i);
		data->philos[i].last_meal_time = data->start_time;
		i++;
	}
}

int	data_init(t_data *data, int philo_count, char **argv)
{
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->status_mutex, NULL);
	pthread_mutex_init(&data->dead_mutex, NULL);
	data->philos = malloc(sizeof(t_philo) * philo_count);
	data->forks = malloc(sizeof(pthread_mutex_t) * philo_count);
	if (!data->philos || !data->forks)
		return (-1);	
	data->start = 0;
	data->stop = 0;
	data->philo_count = philo_count;
	data->tt_die = atoui(argv[2]);
	data->tt_eat = atoui(argv[3]);
	data->tt_sleep = atoui(argv[4]);
	if (argv[5])
		data->meal_num = atoui(argv[5]);
	else
		data->meal_num = -1;
	data->start_time = get_time();
	philo_init(data, philo_count);
	return (0);
}
