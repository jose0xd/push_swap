/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 21:15:29 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/09 10:49:43 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	main(int ac, char **av)
{
	int			*numbers;
	t_stack_ptr	stack_a;
	t_stack_ptr	stack_b;
	t_orders	*orders;

	numbers = parse_numbers(ac - 1, av + 1);
	if (!numbers)
		return (-1);
	stack_a = normalize(&numbers, ac - 1);
	stack_b = NULL;
	orders = NULL;
	if (!is_sort(stack_a))
	{
		if (ac - 1 == 3)
			only_three(&stack_a, &stack_b, &orders);
		else if (ac - 1 <= 5)
			more_than_three(&stack_a, &stack_b, &orders);
		else
			radix(&stack_a, &stack_b, &orders);
	}
	print_orders(orders);
	free(numbers);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free_orders(&orders);
}
