/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:01:28 by msalangi          #+#    #+#             */
/*   Updated: 2025/01/21 22:10:28 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		value_a;
	int		value_b;
	int		div;
	int		mod;

	value_a = *a;
	value_b = *b;
	div = value_a / value_b;
	mod = value_a % value_b;
	a = &div;
	b = &mod;
}
