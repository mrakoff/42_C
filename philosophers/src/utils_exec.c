/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel <mel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 22:12:11 by msalangi          #+#    #+#             */
/*   Updated: 2025/08/13 15:10:47 by mel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	create_threads(t_data *data)
{
	unsigned int	i;

	i = 0;
	if (pthread_create(&data->monitor, NULL, monitor, data) != 0)
		return (1);
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philos[i].thread, NULL, philo_routine, &data->philos[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	stop(t_data *data)
{
	int	stop;

	lock(&data->dead_mutex);
	stop = data->stop;
	unlock(&data->dead_mutex);
	return (stop);
}

void cleanup(t_data *data)
{
	unsigned int i;
	
	i = 0;
	if (data->forks)
	{
		while (i < data->philo_count)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
	}
	if (data->philos)
		free(data->philos);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->dead_mutex);
	pthread_mutex_destroy(&data->status_mutex);
	free(data);
}

void	lock(pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
}

void	unlock(pthread_mutex_t *mutex)
{
	pthread_mutex_unlock(mutex);
}