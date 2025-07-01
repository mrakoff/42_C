/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:00:33 by msalangi          #+#    #+#             */
/*   Updated: 2025/04/11 14:26:18 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	h_ind;
	unsigned int	llen;

	llen = ft_strlen(needle);
	h_ind = 0;
	if (!haystack && len == 0)
		return (NULL);
	if (!needle || needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[h_ind] != '\0' && h_ind + llen <= len)
	{
		if (ft_strncmp(haystack + h_ind, needle, llen) == 0)
			return ((char *)(haystack + h_ind));
		h_ind++;
	}
	return (NULL);
}
