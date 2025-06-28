/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:27:38 by msalangi          #+#    #+#             */
/*   Updated: 2025/06/28 02:45:51 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pushbegin(t_stack **head, int index, int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->value = value;
	node->index = index;
	node->next = *head;
	*head = node;
}

void	pushend(t_stack **head, int index, int value)
{
	t_stack	*node;
	t_stack	*head_tmp;

	node = malloc(sizeof(t_stack));
	node->value = value;
	node->index = index;
	head_tmp = *head;
	node->next = NULL;
	if (head_tmp != NULL)
	{
		while (head_tmp->next != NULL)
			head_tmp = head_tmp->next;
		head_tmp->next = node;
	}
	else
		*head = node;
}

void	removebegin(t_stack **head)
{
	t_stack	*head_tmp;

	if (*head == NULL)
		return ;
	head_tmp = *head;
	*head = (*head)->next;
	free(head_tmp);
}

void	removeend(t_stack **head)
{
	t_stack	*head_tmp;

	if (*head == NULL)
		return ;
	head_tmp = *head;
	if (head_tmp->next == NULL)
	{
		free(head_tmp);
		*head = NULL;
		return ;
	}
	else
	{
		while (head_tmp->next->next != NULL)
			head_tmp = head_tmp->next;
		head_tmp->next = NULL;
		free(head_tmp->next);
	}
}
