/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:47:34 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/13 16:35:54 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_mid_point(stack *s, int start, int end)
{
	int	mid_point;
	int	*arr;
	int	len;
	int	i;

	len = 0;
	i = start;
	while (i++ <= end)
		len++;
	arr = malloc(sizeof(int) * len);
	i = 0;
	while (start <= end)
		arr[i++] = s->items[start++];
	mid_point = quicksort(s, arr, len);
	free(arr);
	return (mid_point);
}

void	ft_sort(stack *s_a, stack *s_b)
{
	int	pivot;
	int	chunks[256];
	int	i;

	i = 0;
	while (s_a->top > 1 && s_a->top != -1)
	{
		if (s_a->top < 5)
			sort_five(s_a, s_b);
		if (is_sorted_a(s_a) == true)
			break ;
		pivot = get_mid_point(s_a, 0, s_a->top);
		chunks[i] = push_to_b(s_a, s_b, pivot, s_a->median);
		i++;
	}
	while (s_b->top > -1 && i >= 0)
	{
		if (is_sorted_a(s_a) == true && s_b->top == -1)
			break;
		while (is_sorted_b(s_b) == true)
			pa(s_a, s_b);
		pivot = get_mid_point(s_b, s_b->top - (chunks[i] - 1), s_b->top);
		push_back_to_a(s_a, s_b, pivot, chunks[i]);
		i--;
	}
}

int	push_to_b(stack *s_a, stack *s_b, int pivot, int median)
{
	int	chunk_len;

	chunk_len = 0;
	while (is_chunk_finished(s_a, pivot) == false)
	{
		if (s_a->items[s_a->top] <= median)
		{
			pb(s_a, s_b);
			if (next_rotate(s_a, pivot) == true)
				rr(s_a, s_b);
			else
				rb(s_b);
			chunk_len++;
		}
		else if (s_a->items[s_a->top] < pivot && s_a->items[s_a->top] > median)
		{
			pb(s_a, s_b);
			chunk_len++;
		}
		else
			which_rotate_a(s_a, pivot);
	}
	if (s_a->items[1] > s_a->items[0] && s_a->top == 1)
			sa(s_a);
	return (chunk_len);
}

void	push_back_to_a(stack *s_a, stack *s_b, int pivot, int chunk)
{
	while (chunk > 0)
	{
		if (ft_smallest(s_b, pivot) == true && chunk > 2)
			pivot = get_mid_point(s_b, s_b->top - (chunk - 1), s_b->top);
		if ((s_b->items[s_b->top] > pivot \
		&& ft_smallest(s_b, s_b->items[s_b->top]) == true) \
		|| is_sorted_b(s_b) == true || (chunk == 1 && \
		ft_smallest(s_b, s_b->items[s_b->top]) == true) \
		|| (s_b->items[s_b->top] == pivot && ft_smallest(s_b, pivot) == true))
		{
			pa(s_a, s_b);
			chunk--;
		}
		else if (s_b->items[s_b->top] < s_b->items[s_b->top - 1] \
		&& ft_smallest(s_b, s_b->items[s_b->top - 1]) == true)
			sb(s_b);
		else
			which_rotate_b(s_b);
	}
}
