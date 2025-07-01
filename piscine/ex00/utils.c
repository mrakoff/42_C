/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-sair <mal-sair@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:06:01 by mal-sair          #+#    #+#             */
/*   Updated: 2025/02/02 23:38:38 by mal-sair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

char	*ft_add_zero(int n)
{
	int		i;
	char	*ptr;

	ptr = malloc(n + 2);
	if (!ptr)
		return (NULL);
	i = 1;
	ptr[0] = '1';
	while (i <= n)
	{
		ptr[i] = '0';
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	print_hundred(char *first_digit,
		char *hundred, t_Data *data_array, int data_count)
{
	print_direct(first_digit, data_array, data_count);
	print_direct(hundred, data_array, data_count);
}
