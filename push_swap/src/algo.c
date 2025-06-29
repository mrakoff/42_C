/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 01:37:21 by msalangi          #+#    #+#             */
/*   Updated: 2025/06/29 04:59:18 by msalangi         ###   ########.fr       */
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
	t_stack	*a = *head_a;

	if (max_ind == 1 || (a->index > a->next->index && a->index < a->next->next->index)) // 213
		return (swap_a(head_a)) ;
	else if (a->index > a->next->index && a->index > a->next->next->index && a->next->index < a->next->next->index) // 312
		return (rotate_a(head_a)) ;
	else if (a->index > a->next->index && a->index > a->next->next->index && a->next->index > a->next->next->index) // 321
		return (swap_a(head_a), rev_a(head_a)) ;
	else if (a->index < a->next->index && a->index > a->next->next->index) // 231
		return (rotate_a(head_a), rotate_a(head_a)) ;
	else if (a->index < a->next->index && a->index < a->next->next->index) // 132
		return (rev_a(head_a), swap_a(head_a)) ;
}

// AAAAAAAAAAAAAAAAAAAAAAAA
void	ft_sort_five(t_stack **head_a, int max_ind)
{
	if (max_ind == 3)
	{
		if ((*head_a)->next->next->next->index == 0)
			rev_a(head_a);
		else
			while ((*head_a)->index != 0)
				rotate_a(head_a);
		ft_sort_three((&(*head_a)->next), 2);
		return ;
	}
	if ((*head_a)->next->next->next->next->index == 0)
		rev_a(head_a);
	else
		while ((*head_a)->index != 0)
			rotate_a(head_a);
	ft_sort_three(head_a, 2);
	ft_sort_three((&(*head_a)->next), 2);
	ft_sort_three((&(*head_a)->next->next), 2);
}


void	radix_sort(t_stack **head_a, t_stack **head_b, int max_ind)
{
	int		bit_pos;
	int		max_bits;
	int		i;

	bit_pos = 0;
	max_bits = 0;
	while (max_ind >> max_bits != 0)
		max_bits++;
	if (max_ind < 3)
		ft_sort_three(head_a, max_ind); // return
	else if (max_ind < 5)
		ft_sort_five(head_a, max_ind); // return
	else // remove after testing
	{
	while (bit_pos <= max_bits)
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
	
	// for testing
	t_stack	*b_curr;
	b_curr = *head_a;
	while (b_curr != NULL)
	{
		printf("stack a: %ld\n", b_curr->value);
		b_curr = b_curr->next;
	}
}
