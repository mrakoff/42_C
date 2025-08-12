/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:49:38 by msalangi          #+#    #+#             */
/*   Updated: 2025/08/10 23:20:20 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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

	lock(&philo->data->mealtime_mutex);
	philo->last_meal_time = get_time();
	unlock(&philo->data->mealtime_mutex);
	
	lock(&philo->data->meal_count_mutex);
	philo->meal_count++;
	unlock(&philo->data->meal_count_mutex);
	
	usleep(philo->data->tt_eat * 100);
	
	unlock(philo->rfork);
	unlock(philo->lfork);
	return (0);
}

static void	nap(t_philo *philo)
{
	print(philo, philo->data, SLEEP);
	usleep(philo->data->tt_sleep);
}

static void	think(t_philo *philo)
{
	print(philo, philo->data, THINK);
}

void	wait_for_threads(t_philo *philo)
{
	// unsigned long	time;

	// time = get_time();
	lock(&philo->data->mealtime_mutex);
	philo->data->start_time = get_time();
	unlock(&philo->data->mealtime_mutex);
	// // while (philo->data->start != 1)
	// {
	// 	// usleep(100);
	// }
	// lock(&philo->data->mealtime_mutex);
	// philo->last_meal_time = get_time();
	// unlock(&philo->data->mealtime_mutex);
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
		nap(philo);
		think(philo);
	}
	return (NULL);
}

