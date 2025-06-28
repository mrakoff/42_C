/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:10:47 by msalangi          #+#    #+#             */
/*   Updated: 2025/06/29 01:16:24 by msalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include "libft/libft.h"
# include <unistd.h> // 
# include <stdio.h> // printf
# include <stdlib.h> // malloc, free


// info about what stack contains
typedef struct s_stack
{
	long			value; // int itself
	unsigned int	index; // it's value's position in the stack
	struct s_stack	*next; // next int info
	
} t_stack;

// ALGO.C
int		ft_is_sorted(t_stack **head_a);
void	ft_sort_three(t_stack **head_a, int max_ind);
void	radix_sort(t_stack **head_a, t_stack **head_b, int max_ind);

// PROCESS_INPUT.C
char	**ft_create_tokens(int argc, char **argv);
int		ft_validate_token(char *token);
int		ft_check_dups(char **tokens);

// MAIN_UTILS.C
int		ft_fill(char **tokens, t_stack **head_a);
int		*ft_create_array(t_stack *head_a, int i);
void	ft_sort(int *unsorted, int len);
void	ft_assign_index(t_stack **head_a, int *array, int len);

// UTILS.C
void	pushbegin(t_stack **head, int index, int value);
void	pushend(t_stack **head, int index, int value);
void	removebegin(t_stack **head);
void	removeend(t_stack **head);

// UTILS_PUSH.C
void	push_a(t_stack **head_a, t_stack **head_b);
void	push_b(t_stack **head_a, t_stack **head_b);

// UTILS_ROTATE.C
void	rotate_a(t_stack **head);
void	rotate_b(t_stack **head);
void	rotate_rr(t_stack **head_a, t_stack **head_b);
void	rev_a(t_stack **head);
void	rev_b(t_stack **head);
void	rev_rr(t_stack **head_a, t_stack **head_b);

// UTILS_SWAP.C
void	swap_a(t_stack **head);
void	swap_b(t_stack **head);
void	swap_ss(t_stack	**head_a, t_stack **head_b);

#endif