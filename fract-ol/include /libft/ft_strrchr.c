/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:40:58 by msalangi          #+#    #+#             */
/*   Updated: 2025/04/11 14:26:20 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*res;

	res = s;
	while (*s)
	{
		if (*s == (char)c)
			res = s;
		s++;
	}
	if (*res == (char)c)
		return ((char *)res);
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
