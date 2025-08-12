/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 01:13:18 by msalangi          #+#    #+#             */
/*   Updated: 2025/08/12 23:02:20 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*		 (1)
*		f + f
*	(4) + + + (2)
*		f + f
*		 (3)
*
*	think -> eat -> sleep -> think -> ..
*	- index % 2
*
*	each philo is represented as a thread
*	3-4 mutexes (time variable, isdead variable, )
*	hellgrind checks // valgrind --tool=helgrind ./philo <args> // valgrind --tool=drd ./philo <args>
*	
*	+ print time in ms
*	+ supervisor thread functions
*		- check if anyone is dead
*		+ check if everyone is full
*	+ eat function
*	- handle one philo (shiould die after tt_die)
*	- wait for threads function
*	- input larger than max int check
*	- separate fuctions / cut lines
*/

#include "../include/philo.h"

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
	// pthread_mutex_destroy(&data->meal_count_mutex);
	// pthread_mutex_destroy(&data->mealtime_mutex);
	free(data);
}

int main(int argc, char **argv)
{
	t_data			*data;
	int				philo_count;
	
	if (!check_input(argc, argv))
		return (write(2, &INVALID, sizeof(INVALID)), 1);

	philo_count = atoui(argv[1]);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);

	// INITIALIZE STUFF
	if (data_init(data, philo_count, argc, argv) == -1)
		return (free(data->philos), free(data->forks), free(data), write(2, &PROBLEM, sizeof(&PROBLEM)), -1);

	// CREATE THREADS
	if (create_threads(data) == -1)
		return (cleanup(data), write(2, &PROBLEM, sizeof(&PROBLEM)), -1);

	// JOIN THREADS
	pthread_join(data->monitor, NULL);

	int i = 0;
	while (i < philo_count)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	// free(data->philos);

	// FREE STUFF
	cleanup(data);
	// printf(RED "Threads finished :P\n" END);
}
