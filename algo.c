/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 20:48:00 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/08 08:33:51 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_sort(t_stack_ptr stack)
{
	t_node	*node;
	t_node	*top;

	if (!stack)
		return (1);
	top = stack->top;
	node = top;
	while (node->next != top)
	{
		if (node->n > node->next->n)
			return (0);
		node = node->next;
	}
	return (1);
}

// stack_b should be empty
void	radix(t_stack_ptr *stack_a, t_stack_ptr *stack_b, t_orders **orders)
{
	int	size;
	int	i;
	int	j;

	size = len_stack(*stack_a);
	i = 0;
	while (1 << i <= size - 1)
	{
		j = 0;
		while (j++ < size)
		{
			if ((top(*stack_a) >> i) & 1)
				do_action("ra", stack_a, stack_b, orders);
			else
				do_action("pb", stack_a, stack_b, orders);
		}
		while (*stack_b)
			do_action("pa", stack_a, stack_b, orders);
		i++;
	}
}

// We compare top to middle, middle to bottom, and bottom to top.
// There are 5 situations (6 if we count the sort situation)
void	only_three(t_stack_ptr *stack_a, t_stack_ptr *stack_b, t_orders **orders)
{
	char	situation;

	situation = 0;
	situation |= ((*stack_a)->top->n > (*stack_a)->top->next->n) << 0;
	situation |= ((*stack_a)->top->next->n > (*stack_a)->top->prev->n) << 1;
	situation |= ((*stack_a)->top->n > (*stack_a)->top->prev->n) << 2;
	if (situation == 1)
		do_action("sa", stack_a, stack_b, orders);
	if (situation == 2)
	{
		do_action("sa", stack_a, stack_b, orders);
		do_action("ra", stack_a, stack_b, orders);
	}
	if (situation == 5)
		do_action("ra", stack_a, stack_b, orders);
	if (situation == 6)
		do_action("rra", stack_a, stack_b, orders);
	if (situation == 7)
	{
		do_action("sa", stack_a, stack_b, orders);
		do_action("rra", stack_a, stack_b, orders);
	}
}

void	more_than_three(t_stack_ptr *stack_a, t_stack_ptr *stack_b, t_orders **orders)
{
	t_node	*max;
	char	*op;

	while (len_stack(*stack_a) > 3)
		do_action("pb", stack_a, stack_b, orders);
	only_three(stack_a, stack_b, orders);
	max = (*stack_a)->top->prev;
	while (*stack_b)
	{
		if (top(*stack_a) > top(*stack_b) && top(*stack_b) > (*stack_a)->top->prev->n)
			do_action("pa", stack_a, stack_b, orders);
		else if ((*stack_a)->top->prev == max && top(*stack_b) > max->n)
		{
			do_action("pa", stack_a, stack_b, orders);
			max = (*stack_a)->top;
		}
		else
			do_action("ra", stack_a, stack_b, orders);
	}
	op = "rra";
	if ((*stack_a)->top == max || (*stack_a)->top->next == max)
		op = "ra";
	while (top(*stack_a) > (*stack_a)->top->prev->n)
		do_action(op, stack_a, stack_b, orders);
}
