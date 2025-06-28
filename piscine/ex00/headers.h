/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:42:03 by mal-sair          #+#    #+#             */
/*   Updated: 2025/02/02 23:06:36 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include <unistd.h> 
# include <stdlib.h>
# include <fcntl.h>

# define NUMBER_SIZE_MAX 1000
# define TEXT_SIZE_MAX 100
# define DICT_ERROR "Dict Error\n"
# define NORMAL_ERROR "ERROR\n"
# define BUFFER_SIZE 1024 
# define MAX_ENTRIES 100

typedef struct Data
{
	char	nbr[NUMBER_SIZE_MAX];
	char	text[TEXT_SIZE_MAX];
}	t_Data;

// typedef struct Num
// {
// 	char	nbr[4];
// 	int		num_zero;
// }	t_Num;
//split.c
char	**split_braces(char *s, int *c);

int		check_if_exist(char *file_name);
int		parse_file(char *file_name, t_Data **data_array, int *data_count);

// dict.c
char	*get_value(char *key, t_Data *data_array, int data_count);

// string_utils.c
void	put_str(char *str);
int		str_len(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);

// add.c
char	*add_braces(char *num);

// print_digit.c
void	print_direct(char *nbr, t_Data *data_array, int data_count);
int		print_two_digits(char *nbr, t_Data *data_array, int data_count);
int		print_three_digits(char *nbr, t_Data *data_array, int data_count);
void	tens_assign(char *nbr, char *tens_only);

// convert.c
int		convert_and_print(char *num, t_Data *data_array, int data_count);

// files.c
void	parse_input(const char *input, t_Data *data);

// parse_input.c
void	ssparse_input(const char *input, t_Data *data);
char	*get_valid_int_string(const char *str);

// utils.c
char	*ft_add_zero(int n);
void	print_hundred(char *first_digit,
			char *hundred, t_Data *data_array, int data_count);

// handle_parts.c
int		handle_four(char *part, t_Data *data_array, int data_count);
int		handle_five(char *part, t_Data *data_array, int data_count);
int		handle_six(char *part, t_Data *data_array, int data_count);

#endif