/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 21:34:12 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/08 21:34:14 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

// stack
typedef struct s_node
{
	int				n;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node	*top;
}			t_stack;

typedef t_stack	*t_stack_ptr;

int		top(t_stack_ptr stack);
void	push(t_stack_ptr *stack, int n);
int		pop(t_stack_ptr *stack);
void	free_stack(t_stack_ptr *stack);
int		len_stack(t_stack_ptr stack);

// actions
void	sx(t_stack_ptr stack);
void	px(t_stack_ptr *dst, t_stack_ptr *src);
void	rx(t_stack_ptr stack);
void	rrx(t_stack_ptr stack);

// qsort
void	ft_qsort(void *array, unsigned int nitems,
			unsigned int size, int (*cmp)(void*, void*));
void	ft_qsort_int(int *array, unsigned int nitems);

// orders
typedef struct s_orders
{
	t_list	*first;
	t_list	*last;
}			t_orders;
void	do_action(char *action, t_stack_ptr *stack_a,
			t_stack_ptr *stack_b, t_orders **orders);
void	print_orders(t_orders *orders);
void	free_orders(t_orders **orders);

// algorithms
int		is_sort(t_stack_ptr stack);
void	radix(t_stack_ptr *stack_a, t_stack_ptr *stack_b, t_orders **orders);
void	only_three(t_stack_ptr *stack_a, t_stack_ptr *stack_b,
			t_orders **orders);
void	more_than_three(t_stack_ptr *stack_a, t_stack_ptr *stack_b,
			t_orders **orders);

// print (only for tests)
void	print_stack(t_stack_ptr stack);

#endif
