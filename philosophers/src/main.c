/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel <mel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 01:13:18 by msalangi          #+#    #+#             */
/*   Updated: 2025/08/13 15:18:44 by mel              ###   ########.fr       */
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

int main(int argc, char **argv)
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
	printf(RED "Simulation ended\n" END);
}
