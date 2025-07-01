/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:51:19 by msalangi          #+#    #+#             */
/*   Updated: 2025/06/27 23:37:40 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_decimal_to_binary(int decimal)
{
	static char	binary_string[9];
	int			ind;

	ind = 0;
	binary_string[8] = '\0';
	while (ind <= 7)
		binary_string[ind++] = '0';
	ind = 7;
	while (decimal)
	{
		if (decimal % 2 == 0 && ind >= 0)
			binary_string[ind--] = '0';
		else if (decimal % 2 == 1 && ind >= 0)
			binary_string[ind--] = '1';
		decimal = decimal / 2;
	}
	return (binary_string);
}

int	ft_binary_to_decimal(char *binary)
{
	int	decimal;
	int	ind;
	int	two;

	decimal = 0;
	ind = 7;
	two = 1;
	while (binary[ind])
	{
		if (binary[ind] == '1' && ind >= 0)
			decimal = decimal + two;
		two = two * 2;
		ind--;
	}
	return (decimal);
}

int	ft_atoi(const char *str)
{
	int	num;

	num = 0;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if ((*str < '0' || *str > '9') && *str != '\0')
		return (-1);
	return (num);
}

char	*ft_itoa(int n)
{
	int			ind;
	static char	str[11];

	ind = 0;
	while (ind < 10)
	{
		str[ind] = '0';
		ind++;
	}
	str[ind] = '\0';
	while (ind > 0)
	{
		str[--ind] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}
