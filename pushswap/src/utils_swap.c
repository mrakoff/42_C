/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel <mel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:50:02 by mel               #+#    #+#             */
/*   Updated: 2025/06/21 19:43:08 by mel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_stack **head)
{
	t_stack	*previous_top;
	t_stack	*new_top;
	t_stack	*head_tmp;
	
	head_tmp = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	new_top = head_tmp->next;
	previous_top = head_tmp;
	
	previous_top->next = new_top->next;
	new_top->next = previous_top;
	
	*head = new_top;
}

void	swap_b(t_stack **head)
{
	t_stack	*previous_top;
	t_stack	*new_top;
	t_stack	*head_tmp;
	
	head_tmp = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	new_top = head_tmp->next;
	previous_top = head_tmp;
	
	previous_top->next = new_top->next;
	new_top->next = previous_top;
	
	*head = new_top;
}

void	swap_ss(t_stack	**head_a, t_stack **head_b)
{
	swap_a(head_a);
	swap_b(head_b);
}
