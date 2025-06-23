/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel <mel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:42:00 by mel               #+#    #+#             */
/*   Updated: 2025/06/22 20:01:22 by mel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort(int *unsorted, int len)
{
	int 	i;
	int		j;

	i = 0;
	j = 0;
	int temp;
	while (i <= len)
	{
		while (j <= len)
		{
			if (unsorted[j] > unsorted[i])
			{
				temp = unsorted[i];
				unsorted[i] = unsorted[j];
				unsorted[j] = temp;
			}
			j++;
		}
		j = 0;
		i++;
	}

	// j = 0;
	// while (j < i)
	// {
	// 	printf("%i\n", *unsorted);
	// 	unsorted++;
	// 	j++;
	// }
}

