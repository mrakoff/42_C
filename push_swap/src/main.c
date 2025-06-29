/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:09:50 by msalangi          #+#    #+#             */
/*   Updated: 2025/06/29 05:03:01 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free(void *stuff1, void *stuff2, void *stuff3)
{
	free(stuff1);
	free(stuff2);
	free(stuff3);
}

// -1 or NULL is returned by all the functions in case of error
// GETTING AN ERROR IF ALL VALUES ARE NEGATIVE - FIX
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
	printf("ft_fill returns this: %i\n", i); // remove
	if (i == -1)
		return (write(2, "Error\n", 6), -1);
	array = ft_create_array(head_a, i);
	ft_sort(array, i - 1);
	ft_assign_index(&head_a, array, i - 1);
	if (ft_is_sorted(&head_a) != 0)
		radix_sort(&head_a, &head_b, i - 1);
	ft_free(tokens, array, head_a);
	// free the whole list - FIX
}
