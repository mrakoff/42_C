/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_braces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:47:47 by mal-sair          #+#    #+#             */
/*   Updated: 2025/02/02 23:39:19 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	f(int n)
{
	if (n % 3 == 0)
		return (2 * n);
	else if (n % 3 == 1)
		return (2 * n + 2);
	else
		return (2 * n + 1);
}

void	add_braces_helper(char *new_num, char *num, int count, int new_i)
{
	int	i;

	i = 0;
	while (i < count)
	{
		new_num[new_i--] = ')';
		new_num[new_i--] = i + '0';
		new_num[new_i--] = '(';
		new_num[new_i--] = num[(count - 1) - i++];
		if (i < count)
			new_num[new_i--] = num[(count - 1) - i++];
		if (i < count)
			new_num[new_i--] = num[(count - 1) - i++];
	}
}

char	*add_braces(char *num)
{
	int		count;
	int		new_i;
	int		new_count;
	char	*new_num;

	count = str_len(num);
	new_count = f(count);
	new_i = new_count - 1;
	new_num = malloc(new_count + 1);
	if (!new_num)
		return (NULL);
	new_num[new_count] = '\0';
	add_braces_helper(new_num, num, count, new_i);
	return (new_num);
}
