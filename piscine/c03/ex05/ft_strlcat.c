/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:49:37 by msalangi          #+#    #+#             */
/*   Updated: 2025/02/03 02:59:00 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	j = 0;
	len = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
		len++;
	}
	j = 0;
	if (size < i)
	{
		while (j <= size)
			j++;
		dest[j - 1] = '\0';
	}
	dest[i] = '\0';
	return ((i - 1) + len);
}

// #include <stdio.h>
// int main(void)
// {
// 	char dest[30] = "this is ";
// 	char src[] = "a string maybe";
// 	unsigned int size = 25;
// 	unsigned int value = ft_strlcat(dest, src, size);
// 	printf("%s, %d", dest, value);
// }