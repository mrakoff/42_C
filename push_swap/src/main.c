/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:09:50 by msalangi          #+#    #+#             */
/*   Updated: 2025/07/04 00:53:02 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free(char **tokens, void *array, t_stack *head_a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
	free(array);
	while (head_a != NULL)
	{
		tmp = head_a->next;
		free(head_a);
		head_a = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;
	char	**tokens;
	int		i;
	int		*array;

	tokens = ft_create_tokens(argc, argv);
	if (tokens == NULL || ft_check_dups(tokens) != 0)
		return (write(2, "Error\n", 6), -1);
	i = ft_fill(tokens, &head_a);
	if (i == -1)
		return (write(2, "Error\n", 6), -1);
	array = ft_create_array(head_a, i);
	ft_sort(array, i - 1);
	ft_assign_index(&head_a, array, i - 1);
	if (ft_is_sorted(&head_a) != 0)
		radix_sort(&head_a, &head_b, i - 1);
	ft_free(tokens, array, head_a);
}
