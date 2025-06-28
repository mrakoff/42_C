/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:41:04 by msalangi          #+#    #+#             */
/*   Updated: 2025/05/28 19:12:43 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		charcount;
	int		n;

	charcount = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			n = ft_check_format(format, args);
			if (n == -1)
				return (-1);
			charcount += n;
		}
		else if (*format != '%' && ft_putchar(*format) != -1)
			charcount++;
		else
			return (-1);
		format++;
	}
	va_end(args);
	return (charcount);
}
