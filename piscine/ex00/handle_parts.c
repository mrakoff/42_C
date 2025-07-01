/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-sair <mal-sair@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:50:41 by mal-sair          #+#    #+#             */
/*   Updated: 2025/02/02 23:44:29 by mal-sair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	handle_four(char *part, t_Data *data_array, int data_count)
{
	char	*num_part;
	int		z;

	num_part = malloc(2);
	if (!num_part)
		return (0);
	num_part[0] = part[0];
	num_part[1] = '\0';
	print_direct(num_part, data_array, data_count);
	z = part[2] - '0';
	free(num_part);
	return (z);
}

int	handle_five(char *part, t_Data *data_array, int data_count)
{
	char	*num_part;
	int		z;

	num_part = malloc(3);
	if (!num_part)
		return (0);
	num_part[0] = part[0];
	num_part[1] = part[1];
	num_part[2] = '\0';
	z = part[3] - '0';
	print_two_digits(num_part, data_array, data_count);
	free(num_part);
	return (z);
}

int	handle_six(char *part, t_Data *data_array, int data_count)
{
	char	*num_part;
	int		z;

	num_part = malloc(4);
	if (!num_part)
		return (0);
	num_part[0] = part[0];
	num_part[1] = part[1];
	num_part[2] = part[2];
	num_part[3] = '\0';
	z = part[4] - '0';
	print_three_digits(num_part, data_array, data_count);
	free(num_part);
	return (z);
}
