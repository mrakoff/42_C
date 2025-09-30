/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 01:13:18 by msalangi          #+#    #+#             */
/*   Updated: 2025/09/06 20:11:32 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// hellgrind checks // valgrind --tool=helgrind ./philo <args>
// valgrind --tool=drd ./philo <args>

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data			*data;
	int				philo_count;
	int				i;

	if (check_input(argc, argv))
		return (write(2, &INVALID, sizeof(INVALID)), 1);
	philo_count = atoui(argv[1]);
	data = malloc(sizeof(t_data));
	if (!data)
		return (printf("%s%s%s", RED, MALLOC_FAIL, END), 1);
	if (data_init(data, philo_count, argv))
		return (cleanup(data), printf("%s%s%s", RED, MALLOC_FAIL, END), 1);
	if (create_threads(data))
		return (cleanup(data), printf("%s%s%s", RED, PROBLEM, END), 1);
	pthread_join(data->monitor, NULL);
	i = 0;
	while (i < philo_count)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	cleanup(data);
	// printf(RED "Simulation ended\n" END);
}
