/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_input_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-sair <mal-sair@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:41:01 by mal-sair          #+#    #+#             */
/*   Updated: 2025/02/02 22:58:07 by mal-sair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int	skip_whitespace_and_sign(const char **s)
{
	while (**s == ' ' || **s == '\t' || **s == '\n'
		|| **s == '\v' || **s == '\f' || **s == '\r')
		(*s)++;
	if (**s == '-')
		return (0);
	if (**s == '+')
		(*s)++;
	return (1);
}

static int	validate(const char *s, const char **start, const char **end)
{
	int	zeroooz;

	zeroooz = 0;
	if (!skip_whitespace_and_sign(&s))
		return (0);
	while (*s == '0')
	{
		s++;
		zeroooz++;
	}
	if (zeroooz > 0)
		s--;
	*start = s;
	while (*s >= '0' && *s <= '9')
		s++;
	if (*start == s)
		return (0);
	if (*s == '.')
		return (0);
	*end = s;
	return (1);
}

char	*allocate_and_copy(const char *start, int len)
{
	char	*digits;
	int		i;
	int		j;

	digits = malloc(len + 1);
	if (!digits)
		return (NULL);
	i = 0;
	j = 0;
	if (start[0] == '0' && len > 1)
		j++;
	while (i < len)
	{
		digits[i] = start[j];
		i++;
		j++;
	}
	digits[i] = '\0';
	return (digits);
}

char	*get_valid_int_string(const char *str)
{
	const char	*start;
	const char	*end;
	int			len;

	if (!validate(str, &start, &end))
		return (NULL);
	len = end - start;
	return (allocate_and_copy(start, len));
}
