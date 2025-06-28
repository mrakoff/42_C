/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:15:31 by msalangi          #+#    #+#             */
/*   Updated: 2025/02/01 17:55:13 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j + 1] == '\0')
			{
				return (&str[i]);
			}
		}
		i++;
	}
	if ((str[i] != to_find[j] && str[i + 1] == '\0') || to_find[0] == '\0')
	{
		return (str);
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	char str[] = "this is a string of characters";
// 	char find[] = "string";
// 	char *value = ft_strstr(str, find);
// 	printf("%s", value);
// }