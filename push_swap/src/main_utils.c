/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:42:00 by mel               #+#    #+#             */
/*   Updated: 2025/06/29 05:05:21 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_fill(char **tokens, t_stack **head_a)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (ft_validate_token(tokens[i]) == 0)
			pushend(head_a, i, ft_atoi(tokens[i]));
		else
			return (-1);
		i++;
	}
	printf("ft_fill %i\n", i);
	return (i);
}

int	*ft_create_array(t_stack *head_a, int i)
{
	int		*array;
	t_stack	*head_tmp;

	array = malloc(sizeof(int) * i + 1);
	array[i] = '\0';
	head_tmp = head_a;
	i = 0;
	while (head_tmp != NULL)
	{
		array[i] = head_tmp->value;
		head_tmp = head_tmp->next;
		i++;
	}
	return (array);
}

void	ft_sort(int *unsorted, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i <= len)
	{
		while (j <= len)
		{
			if (unsorted[j] < unsorted[i])
			{
				temp = unsorted[i];
				unsorted[i] = unsorted[j];
				unsorted[j] = temp;
			}
			j++;
		}
		i++;
		j = i;
	}
}

void	ft_assign_index(t_stack **head_a, int *array, int len)
{
	t_stack	*head_tmp;
	int		i;

	head_tmp = *head_a;
	i = 0;
	while (i <= len)
	{
		while (head_tmp != NULL && head_tmp->value != array[i])
			head_tmp = head_tmp->next;
		head_tmp->index = i;
		i++;
		head_tmp = *head_a;
	}
}
