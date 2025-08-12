/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 01:19:35 by msalangi          #+#    #+#             */
/*   Updated: 2025/08/12 15:22:08 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>		// printf
# include <unistd.h>
# include <pthread.h>	// threads functions
# include <stdlib.h>	// malloc, free
# include <sys/time.h>	// time

# define INVALID	"Invalid arguments, try again\n"
# define PROBLEM	"Problem creating a thread\n"

# define TAKES_FORK	" has taken a fork\n"
# define EAT		" is eating\n"
# define SLEEP		" is sleeping\n"
# define THINK		" is thinking\n"
# define DIE		" died\n"
# define FULL		"\nEveryone is full!\n"

# define GREEN		"\033[1m\033[32m"
# define RED		"\033[1m\033[31m"
# define END		"\033[0m"

// individual philo data
typedef struct	s_philo
{
	pthread_t		thread;			// thread
	pthread_mutex_t	*rfork;			// pointer to fork-mutex in data
	pthread_mutex_t	*lfork;			// pointer to fork-mutex in data

	unsigned int	index;			// index of philo
	unsigned long	last_meal_time;	// last meal timestamp
	int				meal_count;		// meals eaten
	struct s_data	*data;			// pointer to the shared data struct
}	t_philo;

// shared data
typedef struct	s_data
{
	pthread_t		monitor;	// monitoring thread
	t_philo			*philos;	// array of philos
	pthread_mutex_t	*forks;		// array of fork-mutexes

	unsigned long		start_time;		// start time of the program
	unsigned int		philo_count;	// number of philos
	unsigned long		tt_die;			// time to die
	unsigned long		tt_eat;			// time to eat
	unsigned long		tt_sleep;		// time to sleep
	int					meal_num;		// number of times a philo must eat [optional]

	int				start;
	int				stop;

	pthread_mutex_t	print_mutex;
	pthread_mutex_t	status_mutex;
	pthread_mutex_t	meal_count_mutex;
	pthread_mutex_t	mealtime_mutex;
	pthread_mutex_t	dead_mutex;
	

}	t_data;

// INIT.C
int					data_init(t_data *data, int philo_count, int argc, char **argv);

// UTILS_INPUT.C
int					check_input(int argc, char **argv);

// UTILS_PHILO.C
int	create_threads(t_data *data);

// UTILS.C
long				atoui(const char *str);
unsigned long		get_time(void);
void				print(t_philo *philo, t_data *data, char *status);
void				lock(pthread_mutex_t *mutex);
void				unlock(pthread_mutex_t *mutex);

// PHILO_ROUTINE.C
void				*philo_routine(void *arg);

// MONITOR.C
void				*monitor(void *data);
int					stop(t_data *data);


#endif