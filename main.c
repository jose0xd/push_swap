/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 21:15:29 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/08 21:33:08 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static int	n_in_array(int n, int *array, int len)
{
	while (len-- > 0)
		if (n == *array++)
			return (1);
	return (0);
}

static int	valid_number(char *str)
{
	if (!str)
		return (0);
	if (!ft_isdigit(*str) && *str != '-' && *str != '+')
		return (0);
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	*parse_numbers(int ac, char **av)
{
	int	*numbers;
	int	len;
	int	num;

	numbers = (int *)malloc(ac * sizeof(int));
	len = 0;
	while (len < ac)
	{
		if (!valid_number(av[len]))
		{
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
		num = ft_atoi(av[len]);
		if (n_in_array(num, numbers, len)
			|| ((num == 0 || num == -1) && ft_strlen(av[len]) > 2))
		{
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
		numbers[len++] = num;
	}
	return (numbers);
}

static t_stack_ptr	normalize(int **input, int len)
{
	int			*copy;
	int			i;
	t_stack_ptr	stack;
	int			n;
	int			*temp;

	copy = (int *)malloc(len * sizeof(int));
	if (!copy)
		return (NULL);
	copy = ft_memcpy(copy, *input, len * sizeof(int));
	ft_qsort_int(copy, len);
	stack = NULL;
	i = len;
	while (--i >= 0)
	{
		n = 0;
		while ((*input)[i] != copy[n])
			n++;
		push(&stack, n);
	}
	temp = *input;
	*input = copy;
	free(temp);
	return (stack);
}

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