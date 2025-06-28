/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:01:31 by msalangi          #+#    #+#             */
/*   Updated: 2025/01/26 02:55:55 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 32) || (str[i] > 127))
		{
			return (0);
		}
		else if ((str[i] >= 32) && (str[i] <= 127))
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
