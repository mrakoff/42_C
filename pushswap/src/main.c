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
	char	**validated_tokens;
	t_stack	stack_a;
	// t_stack b;
	
	// process the input
	validated_tokens = ft_process_input(argc, argv);
	if (validated_tokens == NULL)
		ft_printf("Error\n");

	// store the data in the struct
	ft_fill_stack(validated_tokens, &stack_a);
}