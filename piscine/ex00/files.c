/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:31:37 by mal-sair          #+#    #+#             */
/*   Updated: 2025/02/02 23:39:37 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static void	skip_spaces(const char *input, int *i)
{
	while (input[*i] == ' ' || input[*i] == '\t')
		(*i)++;
}

void	parse_input(const char *input, t_Data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	skip_spaces(input, &i);
	while (input[i] >= '0' && input[i] <= '9' && j < NUMBER_SIZE_MAX - 1)
		data->nbr[j++] = input[i++];
	data->nbr[j] = '\0';
	skip_spaces(input, &i);
	i++;
	skip_spaces(input, &i);
	j = 0;
	while (input[i] != '\0' && input[i] != '\n' && j < TEXT_SIZE_MAX - 1)
		data->text[j++] = input[i++];
	data->text[j] = '\0';
}

int	check_if_exist(char *file_name)
{
	int	found;

	found = open(file_name, 0);
	close(found);
	return (found != -1);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	buffer;
	int		i;
	int		bytes_read;

	line = malloc(BUFFER_SIZE);
	if (!line)
		return (NULL);
	i = 0;
	while (1)
	{
		bytes_read = read(fd, &buffer, 1);
		if (bytes_read <= 0)
			break ;
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
	}
	line[i] = '\0';
	if (bytes_read <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	parse_file(char *file_name, t_Data **data_array, int *data_count)
{
	int		fd;
	int		count;
	char	*line;
	t_Data	*temp_array;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	temp_array = malloc(MAX_ENTRIES * (TEXT_SIZE_MAX + NUMBER_SIZE_MAX));
	if (!temp_array)
		return (0);
	count = 0;
	while (count < MAX_ENTRIES)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parse_input(line, &temp_array[count]);
		count++;
		free(line);
	}
	*data_array = temp_array;
	*data_count = count;
	close(fd);
	return (1);
}
