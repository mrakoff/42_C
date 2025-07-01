/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-sair <mal-sair@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:50:45 by mal-sair          #+#    #+#             */
/*   Updated: 2025/02/02 23:38:53 by mal-sair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	part_count(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == ')')
			c++;
		i++;
	}
	return (c);
}

char	*ft_sub_str(char *s, int st, int l)
{
	char	*d;
	int		i;

	i = 0;
	d = (char *)malloc(l + 1);
	if (!d)
		return (NULL);
	while (i < l)
	{
		d[i] = s[st + i];
		i++;
	}
	d[i] = 0;
	return (d);
}

char	**split_braces_helper(char *s, char **r, int c)
{
	int	i;
	int	j;
	int	st;

	i = 0;
	j = 0;
	st = 0;
	while (s[i] && j < c)
	{
		if (s[i] == ')')
		{
			r[j] = ft_sub_str(s, st, i - st + 1);
			if (!r[j])
				return (0);
			j++;
			st = i + 1;
		}
		i++;
	}
	return (r);
}

char	**split_braces(char *s, int *c)
{
	char	**r;

	*c = part_count(s);
	if (!c)
		return (0);
	r = (char **)malloc(sizeof(char *) * (*c + 1));
	if (!r)
		return (NULL);
	r[*c] = 0;
	return (split_braces_helper(s, r, *c));
}

// 1(12)231(9)231(6)233(3)123(0)

// ["1(12)" , "231(9)"]