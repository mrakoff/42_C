/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-sair <mal-sair@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:33:23 by mal-sair          #+#    #+#             */
/*   Updated: 2025/02/02 22:12:22 by mal-sair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

char	*get_value(char *key, t_Data *data_array, int data_count)
{
	int	i;

	i = 0;
	while (i < data_count)
	{
		if (ft_strcmp(key, data_array[i].nbr) == 0)
		{
			return (data_array[i].text);
		}
		i++;
	}
	return (0);
}
