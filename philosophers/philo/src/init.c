/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:03:11 by msalangi          #+#    #+#             */
/*   Updated: 2025/08/10 23:32:21 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	forks_init(pthread_mutex_t *forks, t_philo *philo, unsigned int i)
{
	if (philo->index % 2 == 0)
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
		data->philos[i].last_meal_time = 0;
		forks_init(data->forks, &(data->philos[i]), i);
		i++;
	}
}

int	data_init(t_data *data, int philo_count, int argc, char **argv)
{
	int	i;
	
	i = 0;
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->status_mutex, NULL);
	pthread_mutex_init(&data->dead_mutex, NULL);
	pthread_mutex_init(&data->meal_count_mutex, NULL);
	pthread_mutex_init(&data->mealtime_mutex, NULL);

	data->philos = malloc(sizeof(t_philo) * philo_count);
	data->forks = malloc(sizeof(pthread_mutex_t) * philo_count);
	
	data->start = 0;
	data->stop = 0;
	data->philo_count = philo_count;
	data->tt_die = atoui(argv[2]);
	data->tt_eat = atoui(argv[3]);
	data->tt_sleep = atoui(argv[4]);
	if (argc == 6)
		data->meal_num = atoui(argv[5]);
	else
		data->meal_num = -1;
	philo_init(data, philo_count);
	return (0);
}
