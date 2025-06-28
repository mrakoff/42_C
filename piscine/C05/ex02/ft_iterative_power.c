/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 02:09:08 by msalangi          #+#    #+#             */
/*   Updated: 2025/02/07 05:21:31 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power == 0)
	{
		return (1);
	}
	if (nb == 0 || power < 0)
	{
		return (0);
	}
	while (power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}

// #include <stdio.h>
// int main(void)
// {
// 	int test = ft_iterative_power(4, 4);
// 	printf("%i\n", test);
// }