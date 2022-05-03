#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

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

t_list	*make_stack(int *numbers, int len)
{
	t_list	*stack;

	stack = NULL;
	while (--len >= 0)
		ft_lstadd_front(&stack, ft_lstnew(&numbers[len]));
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
	int i = -1;
	t_list	*stack;

	while (++i < ac - 1)
		printf("%d: %d\n", i, numbers[i]);
	
	stack = make_stack(numbers, ac - 1);
	while (stack)
	{
		printf("stack: %d\n", *((int *)stack->content));
		stack = stack->next;
	}
}
