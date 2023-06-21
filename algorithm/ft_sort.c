/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:47:34 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/19 15:30:55 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_mid_point(t_stack *s, int start, int end)
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

void	ft_sort(t_stack *s_a, t_stack *s_b)
{
	int	pivot;
	int	guard;

	guard = 0;
	while (s_a->top > 1 && s_a->top != -1)
	{
		if (s_a->top < 5)
			sort_five(s_a, s_b);
		if (is_sorted_a(s_a) == true)
			break ;
		pivot = get_mid_point(s_a, 0, s_a->top);
		push_to_b(s_a, s_b, pivot);
	}
	push_back_to_a(s_a, s_b, guard);
}

void	push_to_b(t_stack *s_a, t_stack *s_b, int pivot)
{
	while (is_chunk_finished(s_a, s_a->median) == false)
	{
		if (s_a->items[s_a->top] <= s_a->median)
		{
			pb(s_a, s_b);
			if (next_rotate(s_a, pivot) == true \
			&& s_a->items[s_a->top] > pivot)
				rr(s_a, s_b);
			else
				rb(s_b);
		}
		else if (s_a->items[s_a->top] <= pivot)
			pb(s_a, s_b);
		else
			ra(s_a);
	}
}

void	push_back_to_a(t_stack *s_a, t_stack *s_b, int guard)
{
	while (s_b->top > -1)
	{
		next_swap(s_a, s_b, guard);
		if (ft_biggest(s_b, s_b->items[s_b->top]) == true \
		|| is_sorted_b(s_b) == true)
		{
			pa(s_a, s_b);
			if (guard == 1)
				guard--;
		}
		else if (ft_second_biggest(s_b, s_b->items[s_b->top]) == true \
		&& guard == 0 && s_a->top > 5)
		{
			pa(s_a, s_b);
			guard++;
		}
		else
			which_rotate_b(s_b, guard);
	}
	if (s_a->items[s_a->top] > s_a->items[s_a->top - 1])
		sa(s_a);
}
