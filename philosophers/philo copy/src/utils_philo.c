/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 22:12:11 by msalangi          #+#    #+#             */
/*   Updated: 2025/08/12 20:27:44 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	create_threads(t_data *data)
{
	unsigned int	i;

	i = 0;
	if (pthread_create(&data->monitor, NULL, monitor, data) != 0)
		return (-1);
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philos[i].thread, NULL, philo_routine, &data->philos[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}
