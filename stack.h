/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 08:21:42 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/07 09:42:42 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

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
void	print_stack(t_stack_ptr stack);

void	sx(t_stack_ptr stack);
void	px(t_stack_ptr *dst, t_stack_ptr *src);
void	rx(t_stack_ptr stack);
void	rrx(t_stack_ptr stack);

void	ft_qsort(void *array, unsigned int nitems,
			unsigned int size, int (*cmp)(void*, void*));
void	ft_qsort_int(int *array, unsigned int nitems);

typedef struct s_orders
{
	t_list	*first;
	t_list	*last;
}			t_orders;

void	do_action(char *action, t_stack_ptr *stack_a,
			t_stack_ptr *stack_b, t_orders **orders);
void	print_orders(t_orders *orders);
void	free_orders(t_orders **orders);

#endif
