/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:03:35 by msalangi          #+#    #+#             */
/*   Updated: 2025/01/27 19:16:43 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha(char s);
int	is_num(char n);

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] = str[0] - 32;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		if (!is_alpha(str[i - 1]) && is_alpha(str[i]))
		{
			str[i] = str[i] - 32;
		}
		if (is_num(str[i - 1]) && str[i] > 'A' && str[i] < 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

int	is_alpha(char s)
{
	if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z'))
		return (1);
	else
		return (0);
}

int	is_num(char n)
{
	if (n >= 48 && n <= 57)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	char test[] = "salut, comment tu vas ? 42mots";
// 	ft_strcapitalize(test);
// 	printf("%s", test);
// }