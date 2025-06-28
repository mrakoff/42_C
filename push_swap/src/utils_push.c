/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:23:00 by mel               #+#    #+#             */
/*   Updated: 2025/06/28 02:44:50 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(t_stack **head_a, t_stack **head_b)
{
	if (*head_b == NULL)
		return ;
	pushbegin(head_a, (*head_b)->index, (*head_b)->value);
	removebegin(head_b);
	ft_printf("pa\n");
}

void	push_b(t_stack **head_a, t_stack **head_b)
{
	if (*head_a == NULL)
		return ;
	pushbegin(head_b, (*head_a)->index, (*head_a)->value);
	removebegin(head_a);
	ft_printf("pb\n");
}
