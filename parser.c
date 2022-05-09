/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:50:27 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/09 10:50:29 by jarredon         ###   ########.fr       */
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
	if ((*str == '-' || *str == '+') && *(str + 1) != '\0')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	*parse_numbers(int ac, char **av)
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
			free(numbers);
			return (NULL);
		}
		num = ft_atoi(av[len]);
		if (n_in_array(num, numbers, len)
			|| ((num == 0 || num == -1) && ft_strlen(av[len]) > 2))
		{
			ft_putstr_fd("Error\n", 2);
			free(numbers);
			return (NULL);
		}
		numbers[len++] = num;
	}
	return (numbers);
}

t_stack_ptr	normalize(int **input, int len)
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
