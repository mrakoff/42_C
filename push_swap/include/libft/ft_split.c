/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:35:09 by msalangi          #+#    #+#             */
/*   Updated: 2025/04/11 01:10:36 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **str, int ind)
{
	int	i;

	i = 0;
	while (i < ind)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	w_count(const char *s, char c)
{
	int					word_count;
	unsigned long		i;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			word_count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (word_count);
}

int	ft_write(char **str, char const *s, char c)
{
	unsigned long	len;
	unsigned int	i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && (*s == c))
			++s;
		while (*s && (*s != c))
		{
			++len;
			++s;
		}
		if (len > 0)
		{
			str[i] = ft_substr(s - len, 0, len);
			if (!(str[i]))
				return (ft_free(str, i), 1);
			++i;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char			**str_ptr;
	unsigned int	words;

	if (!s)
		return (NULL);
	words = w_count(s, c);
	str_ptr = malloc(sizeof(char *) * (words + 1));
	if (!str_ptr)
		return (NULL);
	str_ptr[words] = NULL;
	if (ft_write(str_ptr, s, c) == 1)
		return (NULL);
	return (str_ptr);
}
