/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:45:02 by mel               #+#    #+#             */
/*   Updated: 2025/06/29 23:05:03 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_stack **head)
{
	pushend(head, (*head)->index, (*head)->value);
	removebegin(head);
	ft_printf("ra\n");
}

void	rev_a(t_stack **head)
{
	t_stack	*last;

	last = *head;
	while (last->next != NULL)
		last = last->next;
	pushbegin(head, last->index, last->value);
	removeend(head);
	ft_printf("rra\n");
}
