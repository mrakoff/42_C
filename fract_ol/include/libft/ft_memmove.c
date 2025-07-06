/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:44:46 by msalangi          #+#    #+#             */
/*   Updated: 2025/04/11 01:01:06 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pdst;
	char	*psrc;

	pdst = (char *)dst;
	psrc = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (pdst == psrc)
		return (dst);
	if (pdst < psrc)
		ft_memcpy(pdst, psrc, len);
	if (psrc < pdst)
	{
		while (len > 0)
		{
			len--;
			pdst[len] = psrc[len];
		}
	}
	return (dst);
}
