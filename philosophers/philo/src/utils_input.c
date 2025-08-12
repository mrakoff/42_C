/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 01:15:05 by msalangi          #+#    #+#             */
/*   Updated: 2025/08/10 23:10:41 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	is_num(char *s)
{
	while (*s >= '0' && *s <= '9')
		s++;
	if (*s == '\0')
		return (1);
	return (0);
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (0);
	while (i < argc && is_num(argv[i]))
		i++;
	if (i != argc)
		return (0);
	if (argc == 6 && (argv[5][0] == '\0' || argv[5][0] == '0'))
		return (0);
	return (1);
}

// philo_count > 0, tt_die > 0