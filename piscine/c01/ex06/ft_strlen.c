/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:58:29 by msalangi          #+#    #+#             */
/*   Updated: 2025/01/21 22:10:40 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		count;

	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

// int main(void)
// {
// 	ft_strlen("test");
// }