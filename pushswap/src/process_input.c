/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:27:38 by msalangi          #+#    #+#             */
/*   Updated: 2025/06/13 23:19:14 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* ********************************************************************************************* */
/* PROCESS THE INPUT:                                                                            */
/* + create tokens (separated strings, which contain integer values to compare)                  */
/* + remove the token if it contains anything else than a numeric value                          */
/* - convert to integers                                                                         */
/* - if duplicates = error                                                                       */
/* ********************************************************************************************** */

int	ft_fill_stack(char *token, int index, t_stack *node) // t_stack *a
{
	printf("filling the stack..\n");
	printf("token: %s\n", token);
	printf("index: %i\n", index);
	
	printf("value in struct: %lu\n\n", node->value);
	return (0);
}

// checks if a string sent contains only numerical values
int	ft_validate_token(char *token)
{
	int	i;

	i = 0;
	if (token == NULL)
		return (-1);
	// ft_printf("to check: %s\n", token);
	while (token[i] && ft_isdigit(token[i]) == 1)
		i++;
	if (token[i] != '\0')
		return (-1);
	return (0);
}

char	**ft_create_tokens(int argc, char **argv)
{
	char	**tokens = NULL;

	if (argc < 2)
		return (NULL);
	if (argc == 2)
	{
		tokens = ft_split(argv[1], ' ');
		if (tokens == NULL)
			return (NULL);
	}
	else if (argc > 2)
	{
		ft_printf("handle this\n");
		return (NULL);
	}
	return (tokens);
}
