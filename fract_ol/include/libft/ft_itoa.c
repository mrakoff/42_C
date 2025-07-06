/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:36:55 by msalangi          #+#    #+#             */
/*   Updated: 2025/04/11 00:58:14 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_num(char *str, unsigned int n,
		unsigned int int_len, unsigned int sign)
{
	str[int_len] = '\0';
	while (int_len > 0)
	{
		str[--int_len] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	int_len;
	unsigned int	sign;

	sign = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	int_len = ft_int_len(n) + sign;
	str = (char *)malloc(sizeof(char) * int_len + 1);
	if (!str)
		return (NULL);
	ft_num(str, n, int_len, sign);
	return (str);
}
