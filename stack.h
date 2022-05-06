/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 08:21:42 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/07 08:21:57 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_node
{
	int				n;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node	*top;
}			t_stack;

typedef t_stack	*t_stack_ptr;

int		top(t_stack_ptr stack);
void	push(t_stack_ptr *stack, int n);
int		pop(t_stack_ptr *stack);
void	free_stack(t_stack_ptr *stack);
int		len_stack(t_stack_ptr stack);
void	print_stack(t_stack_ptr stack);

void	sx(t_stack_ptr stack);
void	px(t_stack_ptr *dst, t_stack_ptr *src);
void	rx(t_stack_ptr stack);
void	rrx(t_stack_ptr stack);

void	ft_qsort(void *array, unsigned int nitems,
			unsigned int size, int (*cmp)(void*, void*));
void	ft_qsort_int(int *array, unsigned int nitems);

#endif
