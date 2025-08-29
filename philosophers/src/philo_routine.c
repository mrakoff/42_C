/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel <mel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:49:38 by msalangi          #+#    #+#             */
/*   Updated: 2025/08/13 15:35:51 by mel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	think(t_philo *philo)
{
	print(philo, philo->data, THINK);
}

static void	nap(t_philo *philo, int sleep, unsigned long time)
{
	unsigned long	start_time;

	start_time = get_time();
	if (sleep)
		print(philo, philo->data, SLEEP);
	while (get_time() - start_time < time)
	{
		if (stop(philo->data))
			break;
		usleep(500);
	}
}

static void	eat(t_philo *philo)
{
	if (!philo->index)
	{
		lock(philo->rfork);
		print(philo, philo->data, TAKES_FORK);
		lock(philo->lfork);
		print(philo, philo->data, TAKES_FORK);
	}
	else
	{
		lock(philo->lfork);
		print(philo, philo->data, TAKES_FORK);
		lock(philo->rfork);
		print(philo, philo->data, TAKES_FORK);
	}
	print(philo, philo->data, EAT);
	lock(&philo->data->status_mutex);
	philo->last_meal_time = get_time();
	philo->meal_count++;
	unlock(&philo->data->status_mutex);
	nap(philo, 0, philo->data->tt_eat);
	unlock(philo->rfork);
	unlock(philo->lfork);
}

static void	lonely_philo(t_philo *philo)
{
	nap(philo, 1, philo->data->tt_sleep);
	think(philo);
	lock(philo->rfork);
	print(philo, philo->data, TAKES_FORK);
	unlock(philo->rfork);
	lock(&philo->data->dead_mutex);
	philo->data->stop = 1;
	unlock(&philo->data->dead_mutex);
}

static void	wait_for_threads(t_philo *philo)
{
	lock(&philo->data->status_mutex);
	philo->data->start = 1;
	philo->data->start_time = get_time();
	unlock(&philo->data->status_mutex);

}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = arg;
	data = philo->data;
	wait_for_threads(philo);
	if (data->philo_count == 1)
	{
		lonely_philo(philo);
		return (NULL);
	}
	if (!philo->index % 2)
		usleep(1000);
	while (!stop(data))
	{
		eat(philo);
		if (stop(data))
			break;
		nap(philo, 1, data->tt_sleep);
		if (stop(data))
			break;
		think(philo);
	}
	return (NULL);
}
