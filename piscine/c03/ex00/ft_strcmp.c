/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:43:45 by msalangi          #+#    #+#             */
/*   Updated: 2025/02/01 18:18:35 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		if (s1[i] == s2[i])
		{
			if (s1[i] == '\0' && s2[i] == '0')
			{
				return (0);
			}
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

// int main(void)
// {
// 	char *str1 = "abc";
// 	char *str2 = "abcd";
// 	ft_strcmp(str1, str2);
// }