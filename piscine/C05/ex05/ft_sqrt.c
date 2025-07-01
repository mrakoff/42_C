/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 04:09:36 by msalangi          #+#    #+#             */
/*   Updated: 2025/02/07 05:24:18 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	num;

	num = 1;
	if (nb <= 0)
	{
		return (0);
	}
	while (num * num <= nb)
	{
		if (num * num == nb)
		{
			return (num);
		}
		num++;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	int test = ft_sqrt(9);
// 	printf("%i\n", test);
// }