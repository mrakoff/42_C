/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:09:50 by msalangi          #+#    #+#             */
/*   Updated: 2025/06/13 23:19:28 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// -1 or NULL is returned by all the functions in case of error

int main(int argc, char **argv)
{
	char	**tokens;
	// t_stack	stack_a;
	int		i;
	int		index;

	i = 0;
	index = 1;

	t_stack *head = NULL;
	t_stack *node = (t_stack *)malloc(sizeof(t_stack));
	// node->value = 5;
	node->next = NULL;
	// head = node;
	// node = node->next;

	// printf("%li\n", ->value);
	// process the input
	tokens = ft_create_tokens(argc, argv);
	if (tokens == NULL)
		return (ft_printf("Error\n"), -1);

	// check if tokens are valid and store them in the stack
	while (tokens[i])
	{
		if (ft_validate_token(tokens[i]) == 0)
		{
			// allocate memory for a new node
			// pass pointer to the function and write data to it
			t_stack *node = (t_stack *)malloc(sizeof(t_stack));
			node->value = atoi(tokens[i]);
			node->next = NULL;
			head = node;

			ft_fill_stack(tokens[i], index, head);
			index++;
			node = node->next;
		}
		i++;
	}

	free(tokens);
	free(node);

}