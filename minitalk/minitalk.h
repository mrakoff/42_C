/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:27:28 by msalangi          #+#    #+#             */
/*   Updated: 2025/06/08 23:29:02 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

struct s_byte
{
	int		ind;
	char	received_bits[9];
	char	byte;
};

char	*ft_decimal_to_binary(int decimal);
int		ft_binary_to_decimal(char *binary);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

#endif
