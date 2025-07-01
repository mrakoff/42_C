/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:45:02 by mel               #+#    #+#             */
/*   Updated: 2025/06/28 23:36:48 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_stack **head)
{
	pushend(head, (*head)->index, (*head)->value);
	removebegin(head);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **head)
{
	pushend(head, (*head)->index, (*head)->value);
	removebegin(head);
	ft_printf("rb\n");
}

void	rotate_rr(t_stack **head_a, t_stack **head_b)
{
	rotate_a(head_a);
	rotate_b(head_b);
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

void	rev_b(t_stack **head)
{
	t_stack	*last;

	last = *head;
	while (last->next != NULL)
		last = last->next;
	pushbegin(head, last->index, last->value);
	removeend(head);
	ft_printf("rrb\n");
}

void	rev_rr(t_stack **head_a, t_stack **head_b)
{
	rev_a(head_a);
	rev_b(head_b);
}
