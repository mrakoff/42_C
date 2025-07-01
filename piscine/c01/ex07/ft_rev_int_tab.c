/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:19:36 by msalangi          #+#    #+#             */
/*   Updated: 2025/01/21 21:56:31 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		store;

	i = 0;
	while (i < size)
	{
		store = tab[i];
		tab[i] = tab[size - i - 1];
		printf("%i", tab[i]);
		tab[i] = store;
		i++;
	}
}

int main(void)
{
	int testarray[5] = {1, 2, 3, 4, 5};
	int (*testarrayptr)[5] = &testarray;
	ft_rev_int_tab(*testarrayptr, 5);
// 	for (int i = 0; i < 6; i++)
// 	{
// 		printf("%i", testarray[i]);
// 	}
}