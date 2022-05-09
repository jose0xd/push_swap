/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:45:44 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/09 11:51:14 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker_bonus.h"

char	*get_next_line(int fd);

static int	do_action_2(char *action, t_stack_ptr *stack_a,
		t_stack_ptr *stack_b)
{
	if (!ft_strncmp(action, "rr", 4))
	{
		rx(*stack_a);
		rx(*stack_b);
	}
	else if (!ft_strncmp(action, "rra", 4))
		rrx(*stack_a);
	else if (!ft_strncmp(action, "rrb", 4))
		rrx(*stack_b);
	else if (!ft_strncmp(action, "rrr", 4))
	{
		rrx(*stack_a);
		rrx(*stack_b);
	}
	else
		return (0);
	return (1);
}

static int	do_action(char *action, t_stack_ptr *stack_a,
		t_stack_ptr *stack_b)
{
	if (!ft_strncmp(action, "sa", 4))
		sx(*stack_a);
	else if (!ft_strncmp(action, "sb", 4))
		sx(*stack_b);
	else if (!ft_strncmp(action, "ss", 4))
	{
		sx(*stack_a);
		sx(*stack_b);
	}
	else if (!ft_strncmp(action, "pa", 4))
		px(stack_a, stack_b);
	else if (!ft_strncmp(action, "pb", 4))
		px(stack_b, stack_a);
	else if (!ft_strncmp(action, "ra", 4))
		rx(*stack_a);
	else if (!ft_strncmp(action, "rb", 4))
		rx(*stack_b);
	else if (!do_action_2(action, stack_a, stack_b))
		return (0);
	return (1);
}

static void	process_actions(t_stack_ptr *stack_a,
		t_stack_ptr *stack_b)
{
	char	*action;
	char	*ptr;

	action = get_next_line(0);
	while (action)
	{
		ptr = ft_strchr(action, '\n');
		if (ptr)
			*ptr = '\0';
		if (!do_action(action, stack_a, stack_b))
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		action = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	int			*numbers;
	t_stack_ptr	stack_a;
	t_stack_ptr	stack_b;

	numbers = parse_numbers(ac - 1, av + 1);
	if (!numbers)
		return (-1);
	stack_a = normalize(&numbers, ac - 1);
	stack_b = NULL;
	process_actions(&stack_a, &stack_b);
	if (is_sort(stack_a) && !stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free(numbers);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
