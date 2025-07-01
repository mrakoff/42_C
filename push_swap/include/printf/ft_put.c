/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:50:04 by msalangi          #+#    #+#             */
/*   Updated: 2025/04/10 23:22:31 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	while (*s)
	{
		if (ft_putchar(*s) != 1)
			return (-1);
		s++;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n, const char *format)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		if (ft_putchar('-') != 1)
			return (-1);
		len++;
		n = -n;
	}
	if (n > 9)
	{
		if (ft_putnbr(n / 10, format) == -1 || ft_putnbr(n % 10, format) == -1)
			return (-1);
	}
	else
		if (ft_putchar(n + '0') != 1)
			return (-1);
	return (len += ft_int_len(n, format));
}

int	ft_putnbr_unsigned(unsigned long n, const char *format)
{
	if (n > 9)
	{
		if (ft_putnbr_unsigned(n / 10, format) == -1
			|| ft_putnbr_unsigned(n % 10, format) == -1)
			return (-1);
	}
	else
		if (ft_putchar(n + '0') != 1)
			return (-1);
	return (ft_int_len(n, format));
}
