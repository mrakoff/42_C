/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:43:40 by msalangi          #+#    #+#             */
/*   Updated: 2025/02/05 22:23:35 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb >= 0)
	{
		result = nb - (nb - 1);
		while (nb > 0)
		{
			result = result * nb;
			nb--;
		}
		return (result);
	}
	else
		return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	int n = 4;
// 	int test = ft_iterative_factorial(n);
// 	printf("%i", test);
// }