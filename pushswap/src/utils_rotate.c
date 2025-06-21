/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel <mel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:45:02 by mel               #+#    #+#             */
/*   Updated: 2025/06/21 20:06:33 by mel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_stack **head)
{
	pushend(head, (*head)->index, (*head)->value);
	removebegin(head);
}

void	rotate_b(t_stack **head)
{
	pushend(head, (*head)->index, (*head)->value);
	removebegin(head);
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
	{
		last = last->next;
	}
	pushbegin(head, last->index, last->value);
	removeend(head);
}

void	rev_b(t_stack **head)
{
	t_stack	*last;

	last = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	pushbegin(head, last->index, last->value);
	removeend(head);
}

void	rev_rr(t_stack **head_a, t_stack **head_b)
{
	rev_a(head_a);
	rev_b(head_b);
}