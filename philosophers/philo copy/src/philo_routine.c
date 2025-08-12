/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:49:38 by msalangi          #+#    #+#             */
/*   Updated: 2025/08/12 22:53:31 by msalangi         ###   ########.fr       */
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
	while (get_time() - start_time < time) {
		if (stop(philo->data) == 1)
			break;
		usleep(500);
	}
	// usleep(philo->data->tt_sleep);
}

static int	eat(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		lock(philo->rfork);
		print(philo, philo->data, " picked up right fork\n");
		lock(philo->lfork);
		print(philo, philo->data, " picked up left fork\n");
	}
	else
	{
		lock(philo->lfork);
		print(philo, philo->data, " picked up left fork\n");
		lock(philo->rfork);
		print(philo, philo->data, " picked up right fork\n");
	}
	print(philo, philo->data, EAT);

	lock(&philo->data->status_mutex);
	philo->last_meal_time = get_time();
	philo->meal_count++;
	unlock(&philo->data->status_mutex);
	
	nap(philo, 0, philo->data->tt_eat);

	unlock(philo->rfork);
	unlock(philo->lfork);
	return (0);
}


void	wait_for_threads(t_philo *philo)
{
	lock(&philo->data->status_mutex);
	philo->data->start = 1;
	philo->data->start_time = get_time();
	unlock(&philo->data->status_mutex);

}

// the loop runs until a philo dies
void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	
	philo = arg;
	data = philo->data;
	wait_for_threads(philo);
	if (philo->index % 2 == 0)
		usleep(1000);
	while (stop(data) != 1)
	{
		eat(philo);
		if (stop(data) == 1)
			break;
		nap(philo, 1, data->tt_sleep);
		if (stop(data) == 1)
			break;
		think(philo);
	}
	return (NULL);
}

