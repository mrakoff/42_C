/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:27:38 by msalangi          #+#    #+#             */
/*   Updated: 2025/06/29 21:10:33 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
			if (ft_atoi(tokens[i]) == ft_atoi(tokens[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

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
	if (ft_strlen(token) > 11 || ft_atoi(token) > 2147483647
		|| ft_atoi(token) < -2147483648)
		return (-1);
	return (0);
}

char	**ft_create_tokens(int argc, char **argv)
{
	char	**tokens;
	char	*unistring;
	char	*tmp;
	int		i;

	i = 1;
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		tokens = ft_split(argv[1], ' ');
	else
	{
		unistring = ft_strdup("");
		while (argc > i)
		{
			tmp = ft_strjoin(unistring, argv[i++]);
			free(unistring);
			unistring = ft_strjoin(tmp, " ");
			free(tmp);
		}
		tokens = ft_split(unistring, ' ');
	}
	if (!tokens[1])
		return (NULL);
	return (free(unistring), tokens);
}
