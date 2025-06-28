/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-sair <mal-sair@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:50:41 by mal-sair          #+#    #+#             */
/*   Updated: 2025/02/02 22:28:35 by mal-sair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static void	process_one_part(char *p, t_Data *d_array, int d_count)
{
	int		zero_count;
	char	*tmp;
	int		len_temp;

	len_temp = str_len(p);
	if (len_temp == 4)
		zero_count = handle_four(p, d_array, d_count);
	else if (len_temp == 5)
		zero_count = handle_five(p, d_array, d_count);
	else
		zero_count = handle_six(p, d_array, d_count);
	if (p[0] == '0' && p[1] == '0' && p[2] == '0')
		zero_count = 0;
	if (zero_count)
	{
		tmp = ft_add_zero(zero_count);
		print_direct(tmp, d_array, d_count);
		free(tmp);
	}
}

static void	convert_loop(char **parts, int len_of_parts,
	t_Data *data_array, int data_count)
{
	int	i;

	i = 0;
	while (i < len_of_parts)
	{
		process_one_part(parts[i], data_array, data_count);
		i++;
	}
}

int	convert_and_print(char *num, t_Data *data_array, int data_count)
{
	char	*new_num;
	char	**parts;
	int		len_of_parts;

	new_num = add_braces(num);
	parts = split_braces(new_num, &len_of_parts);
	free(new_num);
	convert_loop(parts, len_of_parts, data_array, data_count);
	while (len_of_parts--)
	{
		free(parts[len_of_parts]);
	}
	free(parts);
	return (1);
}
