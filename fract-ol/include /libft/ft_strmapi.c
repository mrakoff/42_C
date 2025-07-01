/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:51:02 by msalangi          #+#    #+#             */
/*   Updated: 2025/03/23 20:07:55 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char c))
{
	char	*new;
	int		ind;

	ind = 0;
	if (!s)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen((const char *)s) + 1);
	if (!new)
		return (NULL);
	while (s[ind])
	{
		new[ind] = f(ind, s[ind]);
		ind++;
	}
	new[ind] = '\0';
	return (new);
}
