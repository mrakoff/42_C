/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel <mel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:09:50 by msalangi          #+#    #+#             */
/*   Updated: 2025/06/22 20:02:53 by mel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// -1 or NULL is returned by all the functions in case of error

int main(int argc, char **argv)
{
	char	**tokens;
	int		i;
	int		*array;

	i = 0;
	t_stack *head_a = NULL;

	// process the input
	tokens = ft_create_tokens(argc, argv);
	if (tokens == NULL)
		return (write(2, "Error\n", 6), -1);

	// check if tokens are valid,  and push them to the stack
	if (ft_check_dups(tokens) != 0)
		return (-1);
	while (tokens[i])
	{
		if (ft_validate_token(tokens[i]) == 0)
			pushend(&head_a, i, ft_atoi(tokens[i]));
		else
		{
			// free?
			return (write(2, "Error\n", 6), -1);
		}
		i++;
	}
	// printf("len of array: %i\n\n", i);
	array = malloc(sizeof(int) * i + 1);
	array[i] = '\0';
	i = 0;

	// create an array with values
	t_stack *head_tmp;
	head_tmp = head_a;
	while (head_tmp != NULL)
	{
		array[i] = head_tmp->value;
		head_tmp = head_tmp->next;
		// printf("in: %i\n", array[i]);
		i++;
	}
	// sort the array
	int len = i - 1; 
	ft_sort(array, len);

	//assign index to each value in the stack
	head_tmp = head_a;
	i = 0;
	while (i <= len)
	{
		while (head_tmp != NULL && head_tmp->value != array[i])
		{
			head_tmp = head_tmp->next;
		}
		head_tmp->index = i;
		i++;
		head_tmp = head_a;
	}
	
	// for testing
	head_tmp = head_a;
	while (head_tmp != NULL)
	{
		printf("index: %i\n", head_tmp->index);
		printf("value: %li\n\n", head_tmp->value);
		head_tmp = head_tmp->next;
	}

	free(tokens);
	free(array);
	// free the whole list
}
