/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:30:14 by msalangi          #+#    #+#             */
/*   Updated: 2025/09/06 19:30:29 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	wait_for_threads(t_philo *philo)
{
	lock(&philo->data->status_mutex);
	philo->data->start = 1;
	philo->data->start_time = get_time();
	unlock(&philo->data->status_mutex);
}
