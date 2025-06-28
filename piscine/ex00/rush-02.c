/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-sair <mal-sair@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:03:11 by mal-sair          #+#    #+#             */
/*   Updated: 2025/02/02 23:01:02 by mal-sair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	set_dict_name(int argc, char **argv, char **dict_name)
{
	if (argc == 3)
		*dict_name = argv[2];
	else
		*dict_name = "numbers.dict";
}

int	main(int argc, char **argv)
{
	t_Data	*data_array;
	int		data_count;
	char	*valid_num;
	char	*dict_name;

	if (argc != 2 && argc != 3)
	{
		put_str(NORMAL_ERROR);
		return (1);
	}
	valid_num = get_valid_int_string(argv[1]);
	if (!valid_num)
	{
		put_str(NORMAL_ERROR);
		return (1);
	}
	set_dict_name(argc, argv, &dict_name);
	if (!parse_file(dict_name, &data_array, &data_count))
		return (put_str(DICT_ERROR), 1);
	convert_and_print(valid_num, data_array, data_count);
	free(valid_num);
	free(data_array);
	return (0);
}
