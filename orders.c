#include <stdlib.h>
#include "libft.h"

#include "stack.h"

/*typedef struct s_orders*/
/*{*/
	/*t_list	*first;*/
	/*t_list	*last;*/
/*}			t_orders;*/

static void	add_order(t_orders **orders, char *instr)
{
	t_list	*new_order;

	new_order = ft_lstnew(ft_strdup(instr));
	if (!*orders)
	{
		*orders = (t_orders *)malloc(sizeof(t_orders));
		(*orders)->first = new_order;
		(*orders)->last = new_order;
	}
	else
		ft_lstadd_back(&((*orders)->last), new_order);
}

static void	do_action_2(char *action, t_stack_ptr *stack_a,
		t_stack_ptr *stack_b)
{
	if (!ft_strncmp(action, "rra", 4))
		rrx(*stack_a);
	else if (!ft_strncmp(action, "rrb", 4))
		rrx(*stack_b);
	else if (!ft_strncmp(action, "rrr", 4))
	{
		rrx(*stack_a);
		rrx(*stack_b);
	}
}

void	do_action(char *action, t_stack_ptr *stack_a,
		t_stack_ptr *stack_b, t_orders **orders)
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
	else if (!ft_strncmp(action, "rr", 4))
	{
		rx(*stack_a);
		rx(*stack_b);
	}
	else
		do_action_2(action, stack_a, stack_b);
	add_order(orders, action);
}

void	print_orders(t_orders *orders)
{
	t_list	*order;

	order = orders->first;
	while (order)
	{
		ft_putstr_fd(order->content, 1);
		ft_putstr_fd("\n", 1);
		order = order->next;
	}
}

void	free_orders(t_orders **orders)
{
	ft_lstclear(&((*orders)->first), free);
	free(*orders);
	*orders = NULL;
}
