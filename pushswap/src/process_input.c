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

int	ft_fill_stack(int token, int index, t_stack *node) // t_stack *a
{
	// printf("filling the stack..\n");

	node->value = token;
	node->index = index;
	printf("value: %lu\n", node->value);
	printf("index: %d\n\n", node->index);
	
	// sort the actual thing - compare values and assign index correctly (if smaller int - smaller index)
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
	char 	*unistring = ft_strdup("");
	int		i;

	i = 1;
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		tokens = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		while (argc > i)
		{
			unistring = ft_strjoin(unistring, argv[i]);
			unistring = ft_strjoin(unistring, " ");
			i++;
		}
		// printf("%s\n", unistring);
		tokens = ft_split(unistring, ' ');
	}
	if (tokens == NULL)
		return (NULL);
	return (tokens);
}
