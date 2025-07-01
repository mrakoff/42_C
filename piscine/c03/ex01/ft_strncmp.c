/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:11:32 by msalangi          #+#    #+#             */
/*   Updated: 2025/02/01 18:32:12 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (n <= 0)
		return (0);
	while (i < n && j < n)
	{
		if (s1[i] - s2[j] == 0)
		{
			if (i == n && j == n)
			{
				return (0);
			}
		}
		else if (s1[i] > s2[j] || s1[i] < s2[j])
		{
			return (s1 - s2);
		}
		i++;
		j++;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	int i = 3;
// 	char *str1 = "abcd";
// 	char *str2 = "abdc";
// 	int value = ft_strncmp(str1, str2, i);
// 	printf("%i\n", value);
// }