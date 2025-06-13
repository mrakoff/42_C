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

void	ft_fill_stack(char **tokens, t_stack *a)
{
	int i = 0;

	ft_printf("filling the stack..\n");
	while (tokens[i])
	{
		if (tokens[i] != NULL)
			ft_printf("token %i: %s\n", i, tokens[i]);
		i++;
	}
	
	a->value = 5;
	ft_printf("value in struct: %lu\n", a->value);
}
static char	**ft_validated_tokens(char **split)
{
	char	**tokens;
	char	*to_check;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tokens = split;
	free(split);
	if (tokens == NULL)
		return (NULL);
	while (tokens[i])
	{
		to_check = tokens[i];
		while (ft_isdigit(to_check[j]) == 1 && to_check[j])
			j++;
		if (to_check[j] != '\0')
		{
			tokens[i][0] = '\0';
		}
		j = 0;
		i++;
	}
	return (tokens);
}

char	**ft_process_input(int argc, char **argv)
{
	char	**tokens = NULL;
	int		i;

	i = 1;
	if (argc < 2)
		return (ft_printf("Error\n"), NULL);
	// split into tokens if one argument
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
	// ft_validated_tokens(tokens);
	return (ft_validated_tokens(tokens));
}
