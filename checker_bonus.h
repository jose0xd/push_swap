/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 21:34:12 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/09 11:45:20 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft.h"

// stack
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

int			top(t_stack_ptr stack);
void		push(t_stack_ptr *stack, int n);
int			pop(t_stack_ptr *stack);
void		free_stack(t_stack_ptr *stack);
int			len_stack(t_stack_ptr stack);

//parser
int			*parse_numbers(int ac, char **av);
t_stack_ptr	normalize(int **input, int len);

// actions
void		sx(t_stack_ptr stack);
void		px(t_stack_ptr *dst, t_stack_ptr *src);
void		rx(t_stack_ptr stack);
void		rrx(t_stack_ptr stack);

// qsort
void		ft_qsort(void *array, unsigned int nitems,
				unsigned int size, int (*cmp)(void*, void*));
void		ft_qsort_int(int *array, unsigned int nitems);

// algorithms
int			is_sort(t_stack_ptr stack);

// print (only for tests)
void		print_stack(t_stack_ptr stack);

#endif
