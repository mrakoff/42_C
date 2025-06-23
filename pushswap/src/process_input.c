/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel <mel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:27:38 by msalangi          #+#    #+#             */
/*   Updated: 2025/06/22 20:04:38 by mel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* ********************************************************************************************* */
/* PROCESS THE INPUT:                                                                            */
/* + create tokens (separated strings, which contain integer values to compare)                  */
/* + remove the token if it contains anything else than a numeric value                          */
/* + convert to integers  - IN MAIN                                                              */
/* + if duplicates = error                                                                       */
/* ********************************************************************************************* */

// checks if there are duplicate tokens
int	ft_check_dups(char **tokens)
{
	int	len1;
	int	len2;
	int	i;
	int	j;
	
	i = 0;
	while (tokens[i])
	{
		j = i + 1;
		while (tokens[j])
		{
			len1 = ft_strlen(tokens[i]);
			len2 = ft_strlen(tokens[j]);
			if (len1 == len2)
			{
				if(ft_strncmp(tokens[i], tokens[j], len1) == 0)
					return (write(2, "Error\n", 6), -1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

// checks if a string sent contains only numerical values
// ALSO ADD NEGATIVE VALUES
// error ifore 
int	ft_validate_token(char *token)
{
	int	i;

	i = 0;
	if (token == NULL)
		return (-1);
	while (token[i] && ft_isdigit(token[i]) == 1)
		i++;
	if (token[i] != '\0')
		return (-1);
	return (0);
}

// LEAKS !!

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
		tokens = ft_split(unistring, ' ');
	}
	if (tokens == NULL)
		return (NULL);
	return (tokens);
}
