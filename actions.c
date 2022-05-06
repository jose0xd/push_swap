/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:38:36 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/06 13:38:39 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	sx(t_stack_ptr stack)
{
	int	temp;

	if (!stack)
		return ;
	temp = stack->top->n;
	stack->top->n = stack->top->next->n;
	stack->top->next->n = temp;
}

void	px(t_stack_ptr *dst, t_stack_ptr *src)
{
	if (!*src)
		return ;
	push(dst, pop(src));
}

void	rx(t_stack_ptr stack)
{
	if (!stack)
		return ;
	stack->top = stack->top->next;
}

void	rrx(t_stack_ptr stack)
{
	if (!stack)
		return ;
	stack->top = stack->top->prev;
}
