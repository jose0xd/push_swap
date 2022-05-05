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

int	main(int ac, char **av)
{
	int	*numbers = parse_numbers(ac - 1, av + 1);
	if (!numbers)
	{
		puts("Numeros repetidos");
		return (-1);
	}

	t_stack_ptr	stack = NULL;
	int i = ac - 1;
	while (--i >= 0)
		push(&stack, numbers[i]);
	print_stack(stack);

	t_stack_ptr stack_b = NULL;
	char	op[20];
	while (42)
	{
		scanf("%s", op);
		if (!ft_strncmp(op, "sa", 2))
			sx(stack);
		else if (!ft_strncmp(op, "pa", 2))
			px(&stack, &stack_b);
		else if (!ft_strncmp(op, "pb", 2))
			px(&stack_b, &stack);
		else if (!ft_strncmp(op, "ra", 2))
			rx(stack);
		else if (!ft_strncmp(op, "rra", 3))
			rrx(stack);
		else if (!ft_strncmp(op, "q", 1))
			break;
		puts("------------");
		print_stack(stack);
		puts("............");
		print_stack(stack_b);
	}
	print_stack(stack);

		


	free_stack(&stack);
}
