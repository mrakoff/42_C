/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:50:02 by mel               #+#    #+#             */
/*   Updated: 2025/06/29 20:15:10 by msalangi         ###   ########.fr       */
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
	ft_printf("sa\n");
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
	ft_printf("sb\n");
}
