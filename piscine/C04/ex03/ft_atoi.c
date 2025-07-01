/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:21:44 by msalangi          #+#    #+#             */
/*   Updated: 2025/02/05 00:11:18 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		new;

	i = 0;
	sign = 1;
	new = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		new = new * 10 + (str[i] - '0');
		i++;
	}
	return (new * sign);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *test = "    -+++--4242m42test";
// 	int result = ft_atoi(test);
// 	printf("%i", result);
// }