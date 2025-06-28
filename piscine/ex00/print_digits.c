/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:28:11 by mal-sair          #+#    #+#             */
/*   Updated: 2025/02/02 23:21:01 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	print_direct(char *nbr, t_Data *data_array, int data_count)
{
	static int	first_print = 1;
	char		*value;

	value = get_value(nbr, data_array, data_count);
	if (!value)
	{
		put_str(DICT_ERROR);
		return ;
	}
	if (!first_print)
		put_str(" ");
	else
		first_print = 0;
	put_str(value);
}

void	tens_assign(char *nbr, char *tens_only)
{
	tens_only[0] = nbr[0];
	tens_only[1] = '0';
	tens_only[2] = '\0';
}

int	print_two_digits(char *nbr, t_Data *data_array, int data_count)
{
	char	onestring[2];
	char	tens_only[3];

	if (!ft_strcmp(nbr, "00"))
		return (0);
	if (nbr[0] == '1')
		print_direct(nbr, data_array, data_count);
	else if (nbr[0] == '0')
	{
		onestring[0] = nbr[1];
		onestring[1] = '\0';
		print_direct(onestring, data_array, data_count);
	}
	else
	{
		tens_assign(nbr, tens_only);
		print_direct(tens_only, data_array, data_count);
		if (nbr[1] != '0')
		{
			onestring[0] = nbr[1];
			onestring[1] = '\0';
			print_direct(onestring, data_array, data_count);
		}
	}
	return (1);
}

void	prepare_and_print_hundred(char *nbr, char *hundred,
		char *first_digit, char *last_two)
{
	ft_strcpy(hundred, "100");
	first_digit[0] = nbr[0];
	first_digit[1] = '\0';
	last_two[0] = nbr[1];
	last_two[1] = nbr[2];
	last_two[2] = '\0';
}

int	print_three_digits(char *nbr, t_Data *data_array, int data_count)
{
	char	hundred[4];
	char	first_digit[2];
	char	last_two[3];

	if (!ft_strcmp(nbr, "000"))
		return (0);
	prepare_and_print_hundred(nbr, hundred, first_digit, last_two);
	if (first_digit[0] != '0')
		print_hundred(first_digit, hundred, data_array, data_count);
	print_two_digits(last_two, data_array, data_count);
	return (1);
}
