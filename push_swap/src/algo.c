/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 01:37:21 by msalangi          #+#    #+#             */
/*   Updated: 2025/06/29 23:03:57 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_is_sorted(t_stack **head_a)
{
	t_stack	*a_tmp;

	a_tmp = *head_a;
	while (a_tmp->next != NULL)
	{
		if (a_tmp->index < a_tmp->next->index)
			a_tmp = a_tmp->next;
		else
			break ;
	}
	if (a_tmp->next == NULL)
		return (0);
	return (-1);
}

void	ft_sort_three(t_stack **head_a, int max_ind)
{
	t_stack	*a;

	a = *head_a;
	if (max_ind == 1 || (a->index > a->next->index
			&& a->index < a->next->next->index))
		return (swap_a(head_a));
	else if (a->index > a->next->index && a->index > a->next->next->index
		&& a->next->index < a->next->next->index)
		return (rotate_a(head_a));
	else if (a->index > a->next->index && a->index > a->next->next->index
		&& a->next->index > a->next->next->index)
		return (swap_a(head_a), rev_a(head_a));
	else if (a->index < a->next->index && a->index > a->next->next->index)
		return (rotate_a(head_a), rotate_a(head_a));
	else if (a->index < a->next->index && a->index < a->next->next->index)
		return (rev_a(head_a), swap_a(head_a));
}

void	ft_sort_five(t_stack **head_a, t_stack **head_b)
{
	if ((*head_a)->next->next->next->next->index == 0)
	{
		rev_a(head_a);
		push_b(head_a, head_b);
	}
	else
	{
		while ((*head_a)->index != 0)
			rotate_a(head_a);
		push_b(head_a, head_b);
	}
	if ((*head_a)->next->next->next->index == 1)
	{
		rev_a(head_a);
		push_b(head_a, head_b);
	}
	else
	{
		while ((*head_a)->index != 1)
			rotate_a(head_a);
		push_b(head_a, head_b);
	}
	ft_sort_three(head_a, 2);
	push_a(head_a, head_b);
	push_a(head_a, head_b);
}

void	radix_sort(t_stack **head_a, t_stack **head_b, int max_ind)
{
	static int		bit_pos;
	int				max_bits;
	int				i;

	max_bits = 0;
	while (max_ind >> max_bits != 0)
		max_bits++;
	if (max_ind < 3)
		return (ft_sort_three(head_a, max_ind));
	else if (max_ind == 4)
		return (ft_sort_five(head_a, head_b));
	while (bit_pos < max_bits)
	{
		i = 0;
		while (i++ <= max_ind)
		{
			if (((*head_a)->index >> bit_pos) & 1)
				rotate_a(head_a);
			else
				push_b(head_a, head_b);
		}
		bit_pos++;
		while (*head_b != NULL)
			push_a(head_a, head_b);
	}
}
