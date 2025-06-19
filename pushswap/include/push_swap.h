/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalangi <msalangi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:10:47 by msalangi          #+#    #+#             */
/*   Updated: 2025/06/13 23:16:59 by msalangi         ###   ########.fr       */
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
	int				index; // it's position in the stack
	struct s_stack	*next; // next int info
	// struct s_stack	*head; // keeps track of top of the stack
	// struct s_stack	*tail; // keeps track of bottom of the stack
	
} t_stack;

// struct to keep track of both stacks?
typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
} t_stacks;



// PROCESS_DATA.C
char	**ft_create_tokens(int argc, char **argv);
int		ft_validate_token(char *token);
int		ft_fill_stack(char *token, int index, t_stack *head);


#endif