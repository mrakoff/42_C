/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:04:03 by msalangi          #+#    #+#             */
/*   Updated: 2025/04/10 23:29:21 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_len(int n, const char *format)
{
	int				len;
	unsigned int	m;

	len = 0;
	if (n == 0 || ((*format == 'i' || *format == 'd') && n < 0))
		len++;
	if (*format == 'x' || *format == 'X' || *format == 'u')
	{
		m = n;
		while (m)
		{
			if (*format == 'x' || *format == 'X')
				m /= 16;
			else
				m /= 10;
			len++;
		}
		return (len);
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_long_len(unsigned long n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_hexl(unsigned long n, int len, const char *format)
{
	if (n == 0 && len == 0 && ft_putchar('0') != 1)
		return (-1);
	if (!n)
		return (1);
	if (len == 0)
		len = ft_long_len(n);
	if (ft_hexl(n / 16, len, format) == -1)
		return (-1);
	if (n % 16 > 9 && *format == 'p')
	{
		if (ft_putchar('a' + ((n % 16) - 10)) != 1)
			return (-1);
	}
	else if (ft_putnbr(n % 16, format) == -1)
		return (-1);
	return (len);
}

int	ft_hex(unsigned int n, int len, const char *format)
{
	if (n == 0 && len == 0 && ft_putchar('0') != 1)
		return (-1);
	if (!n)
		return (1);
	if (len == 0)
		len = ft_int_len((unsigned int)n, format);
	if (ft_hex(n / 16, len, format) == -1)
		return (-1);
	if (n % 16 > 9)
	{
		if (*format == 'x' && ft_putchar('a' + ((n % 16) - 10)) != 1)
			return (-1);
		if (*format == 'X' && ft_putchar('A' + ((n % 16) - 10)) != 1)
			return (-1);
	}
	else if (ft_putnbr(n % 16, format) == -1)
		return (-1);
	return (len);
}

int	ft_check_format(const char *format, va_list args)
{
	int	i;

	if (*format == '%')
		return (ft_putchar('%'));
	if (*format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (*format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (*format == 'i' || *format == 'd')
		return (ft_putnbr(va_arg(args, int), format));
	if (*format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int), format));
	if (*format == 'x' || *format == 'X')
		return (ft_hex(va_arg(args, unsigned int), 0, format));
	if (*format == 'p' && ft_putstr("0x") != -1)
	{
		i = ft_hexl(va_arg(args, unsigned long), 0, format);
		if (i != -1)
			return (i + 2);
	}
	return (-1);
}
