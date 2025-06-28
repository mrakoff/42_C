/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 04:38:45 by msalangi          #+#    #+#             */
/*   Updated: 2025/01/22 04:47:56 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'A') || (str[i] > 'Z'))
		{
			return (0);
		}
		else if ((str[i] >= 'A') && (str[i] <= 'Z'))
		{
			if (str[i + 1] == '\0')
			{
				return (1);
			}
		}
		else
		{
			return (1);
		}
		i++;
	}
	return (1);
}

// int main(void)
// {
// 	char *test = "MEoW";
// 	ft_str_is_uppercase(test);
// }