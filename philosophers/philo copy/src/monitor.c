/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:15:16 by msalangi          #+#    #+#             */
/*   Updated: 2025/08/12 22:40:49 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	stop(t_data *data)
{
	int	stop;

	lock(&data->dead_mutex);
	stop = data->stop;
	unlock(&data->dead_mutex);
	return (stop);
}

int	everyone_full(t_data *data)
{
	unsigned int	i;
	int				full;

	i = 0;
	full = 1;
	lock(&data->status_mutex);
	while (i < data->philo_count)
	{
		if (data->philos[i].meal_count < data->meal_num)
		{
			full = 0;
			break ;
		}
		i++;
	}
	unlock(&data->status_mutex);
	return (full);
}

int	died(t_data *data)
{
	unsigned int	i;
	
	i = 0;
	lock(&data->status_mutex);
	lock(&data->mealtime_mutex);
	while (i < data->philo_count)
	{
		// printf("Philo %d: time = %lu, last_meal_time = %lu, tt_die = %lu, diff = %lu\n",
            // data->philos[i].index, get_time(), data->philos[i].last_meal_time, data->tt_die, (get_time() - (data->philos[i].last_meal_time)));
		if (((get_time() - (data->philos[i].last_meal_time)) >= data->tt_die))
		{
			print(&data->philos[i], data, DIE);
			lock(&data->dead_mutex);
			data->stop = 1;
			unlock(&data->dead_mutex);
	
			unlock(&data->mealtime_mutex);
			unlock(&data->status_mutex);
			return (1);
		}
		i++;
	}
	unlock(&data->mealtime_mutex);
	unlock(&data->status_mutex);
	return (0);
}

void	*monitor(void *arg)
{
	t_data			*data;
	unsigned int	i;
	
	data = arg;
	i = 0;
	while (1)
	{
		lock(&data->status_mutex);
		if (data->start)
		{
			unlock(&data->status_mutex);
			break;
		}
		unlock(&data->status_mutex);
		usleep(100);
	}
	while (1)
	{
		if (died(data) == 1)
		{
			break;
		}
		if (data->meal_num > 0 && everyone_full(data) == 1)
		{
			lock(&data->dead_mutex);
			data->stop = 1;
			unlock(&data->dead_mutex);
			print(NULL, data, NULL);
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}