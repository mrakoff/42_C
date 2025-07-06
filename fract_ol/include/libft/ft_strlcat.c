/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:37:32 by msalangi          #+#    #+#             */
/*   Updated: 2025/04/11 14:24:33 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	s_ind;
	unsigned int	d_ind;
	unsigned int	srclen;

	s_ind = 0;
	srclen = ft_strlen(src);
	d_ind = ft_strlen(dst);
	if (dstsize < d_ind)
		return ((size_t)(srclen + dstsize));
	while (src[s_ind] && ((d_ind + s_ind) < (dstsize - 1)) && dstsize > 0)
	{
		dst[d_ind + s_ind] = src[s_ind];
		s_ind++;
	}
	dst[d_ind + s_ind] = '\0';
	return ((size_t)(srclen + d_ind));
}
