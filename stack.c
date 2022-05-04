/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:02:37 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/04 13:02:38 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "stack.h"

// stack cannot be NULL
int	top(t_stack_ptr stack)
{
	return (stack->top->n);
}

void	push(t_stack_ptr *stack, int n)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->n = n;
	if (*stack == NULL)
	{
		*stack = (t_stack *)malloc(sizeof(t_stack));
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node->next = (*stack)->top;
		new_node->prev = (*stack)->top->prev;
		(*stack)->top->prev->next = new_node;
		(*stack)->top->prev = new_node;
		if ((*stack)->top->next == (*stack)->top)
			(*stack)->top->next = new_node;
	}
	(*stack)->top = new_node;
}

// stack cannot be NULL
int	pop(t_stack_ptr *stack)
{
	int		n;
	t_node	*new_top;

	if (*stack == NULL)
		exit(-2);
	n = (*stack)->top->n;
	if ((*stack)->top->prev == (*stack)->top)
	{
		free((*stack)->top);
		free(*stack);
		*stack = NULL;
	}
	else
	{
		(*stack)->top->prev->next = (*stack)->top->next;
		(*stack)->top->next->prev = (*stack)->top->prev;
		new_top = (*stack)->top->next;
		free((*stack)->top);
		(*stack)->top = new_top;
	}
	return (n);
}

void	free_stack(t_stack_ptr *stack)
{
	t_node	*node;

	if (*stack == NULL)
		return ;
	node = (*stack)->top->next;
	while (node != (*stack)->top)
	{
		node = node->next;
		free(node->prev);
	}
	free(node);
	free(*stack);
	*stack = NULL;
}

void	print_stack(t_stack_ptr stack)
{
	t_node	*node;

	if (!stack)
	{
		ft_putstr_fd("Empty stack\n", 1);
		return ;
	}
	node = stack->top;
	ft_putnbr_fd(node->n, 1);
	ft_putchar_fd('\n', 1);
	node = node->next;
	while (node != stack->top)
	{
		ft_putnbr_fd(node->n, 1);
		ft_putchar_fd('\n', 1);
		node = node->next;
	}
}
