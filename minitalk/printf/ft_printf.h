/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:05:02 by msalangi          #+#    #+#             */
/*   Updated: 2025/04/10 23:16:09 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_int_len(int n, const char *format);
int		ft_putchar(char c);
int		ft_putnbr(int n, const char *format);
int		ft_putstr(char *s);
int		ft_printf(const char *format, ...);
int		ft_check_format(const char *format, va_list args);
int		ft_hex(unsigned int n, int len, const char *format);
int		ft_hexl(unsigned long n, int len, const char *format);
int		ft_putnbr_unsigned(unsigned long n, const char *format);

#endif
