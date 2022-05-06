/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:11:23 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/06 13:38:19 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap(void *x, void *y, unsigned int l)
{
	char	*a;
	char	*b;
	char	c;

	a = x;
	b = y;
	while (l--)
	{
		c = *a;
		*a++ = *b;
		*b++ = c;
	}
}

static void	sort(char *array, unsigned int size,
		int (*cmp)(void*, void*), int begin, int end)
{
	void	*pivot;
	int		l;
	int		r;

	pivot = array + begin;
	l = begin + size;
	r = end;
	if (end <= begin)
		return ;
	while (l < r)
	{
		if (cmp(array + l, pivot) <= 0)
			l += size;
		else if (cmp(array + r, pivot) > 0)
			r -= size;
		else if (l < r)
			swap(array + l, array + r, size);
	}
	l -= size;
	if (cmp(array + r, pivot) < 0)
		swap(array + begin, array + r, size);
	else
		swap(array + begin, array + l, size);
	sort(array, size, cmp, begin, l);
	sort(array, size, cmp, r, end);
}

void	ft_qsort(void *array, unsigned int nitems,
		unsigned int size, int (*cmp)(void*, void*))
{
	if (nitems > 0)
		sort(array, size, cmp, 0, (nitems - 1) * size);
}

static int	type_cmp(void *a, void *b)
{
	return ((*(int *)a) - (*(int *)b));
}

void	ft_qsort_int(int *array, unsigned int nitems)
{
	ft_qsort(array, nitems, sizeof(int), type_cmp);
}
