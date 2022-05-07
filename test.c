#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "stack.h"

int	n_in_array(int n, int *array, int len)
{
	while (len-- > 0)
		if (n == *array++)
			return (1);
	return (0);
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
		//TODO comprobar que sean números válidos
		num = ft_atoi(av[len]);
		if (n_in_array(num, numbers, len))
			return (NULL);
		numbers[len++] = num;
	}
	return (numbers);
}

// better name?
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
	while (--i  >= 0)
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
	int	*numbers = parse_numbers(ac - 1, av + 1);
	if (!numbers)
	{
		puts("Numeros repetidos");
		return (-1);
	}

	t_stack_ptr	stack_a;
	stack_a = normalize(&numbers, ac - 1);
	print_stack(stack_a);

	t_stack_ptr stack_b = NULL;
	t_orders	*orders = NULL;
	char	op[20];
	while (42)
	{
		scanf("%s", op);
		if (!ft_strncmp(op, "q", 1))
			break;
		do_action(op, &stack_a, &stack_b, &orders);
		puts("------------");
		print_stack(stack_a);
		printf("........... len A: %d\n", len_stack(stack_a));
		print_stack(stack_b);
		printf("------------ len B: %d\n\n", len_stack(stack_b));
	}
	print_orders(orders);

	free_stack(&stack_a);
	free_stack(&stack_b);
	free_orders(&orders);
	free(numbers);
	system("valgrind test");
}
