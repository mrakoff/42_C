/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:38:46 by msalangi          #+#    #+#             */
/*   Updated: 2025/04/11 01:00:36 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	ind;

	ind = 0;
	if (!dst && !src && n > 0)
		return (NULL);
	while (ind < n)
	{
		*(char *)(dst + ind) = *(char *)(src + ind);
		ind++;
	}
	return (dst);
}
