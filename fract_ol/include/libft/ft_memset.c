/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:17:16 by msalangi          #+#    #+#             */
/*   Updated: 2025/04/11 01:01:48 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	b_ind;

	b_ind = 0;
	while (b_ind < len)
	{
		*((char *)b + b_ind) = c;
		b_ind++;
	}
	return (b);
}
