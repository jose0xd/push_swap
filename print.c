/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:38:54 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/06 13:38:56 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

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
