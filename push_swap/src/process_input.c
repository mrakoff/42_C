/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:27:38 by msalangi          #+#    #+#             */
/*   Updated: 2025/06/28 02:46:02 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// checks if there are duplicate tokens
int	ft_check_dups(char **tokens)
{
	int	i;
	int	j;

	i = 0;
	while (tokens[i])
	{
		j = i + 1;
		while (tokens[j])
		{
			if (atoi(tokens[i]) == atoi(tokens[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

// checks if a string sent contains only numerical values
// TODO: ERROR IF LESS THAN MIN INT OR BIGGER THAN MAX INT
int	ft_validate_token(char *token)
{
	int	i;

	i = 0;
	if (token == NULL)
		return (-1);
	if (token[i] == '-' || token[i] == '+')
		i++;
	while (token[i] && ft_isdigit(token[i]) == 1)
		i++;
	if (token[i] != '\0')
		return (-1);
	if (atoi(token) == -1)
		return (-1);
	return (0);
}

// LEAKS ?
char	**ft_create_tokens(int argc, char **argv)
{
	char	**tokens;
	char	*unistring;
	char	*tmp;
	int		i;

	i = 1;
	tokens = NULL;
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		tokens = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		unistring = ft_strdup("");
		while (argc > i)
		{
			tmp = ft_strjoin(unistring, argv[i++]);
			unistring = ft_strjoin(tmp, " ");
			free(tmp);
		}
		tokens = ft_split(unistring, ' ');
	}
	if (!tokens[1])
		return (NULL);
	return (free(unistring), tokens);
}
