/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 02:44:45 by msalangi          #+#    #+#             */
/*   Updated: 2025/02/07 05:22:10 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if ((nb == 0 && power == 0) || power == 0)
	{
		return (1);
	}
	if (nb == 0 || power < 0)
	{
		return (0);
	}
	return (nb * (ft_recursive_power(nb, power - 1)));
}

// #include <stdio.h>
// int main(void)
// {
// 	int test = ft_recursive_power(4, 5);
// 	printf ("%i\n", test);
// }