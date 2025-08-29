/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel <mel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:15:16 by msalangi          #+#    #+#             */
/*   Updated: 2025/08/13 15:15:55 by mel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	everyone_full(t_data *data)
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

static int	died(t_data *data)
{
	unsigned int	i;

	i = 0;
	lock(&data->status_mutex);
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
			unlock(&data->status_mutex);
			return (1);
		}
		i++;
	}
	unlock(&data->status_mutex);
	return (0);
}

static void	synchronize(t_data *data)
{
	while (1)
	{
		lock(&data->status_mutex);
		if (data->start)
		{
			unlock(&data->status_mutex);
			break ;
		}
		unlock(&data->status_mutex);
		usleep(100);
	}
}

void	*monitor(void *arg)
{
	t_data			*data;

	data = arg;
	synchronize(data);
	while (1)
	{
		if (died(data))
			break;
		if (data->meal_num > 0 && everyone_full(data))
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
