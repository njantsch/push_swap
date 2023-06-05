/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:47:34 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/05 17:38:24 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_mid_point(stack *s, int start, int end)
{
	int	mid_point
	int	*arr;
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (start <= end)
		len++;
	arr = malloc(sizeof(int) * len);
	while (start <= end)
		arr[i++] = s->items[start++];
	mid_point = quicksort(arr, len);
	free(arr);
	return (mid_point);
}

void	ft_sort(stack *s_a, stack *s_b)
{
	int	pivot;
	int	chunks;

	chunks = 0;
	while (s_a->top > 1 && s_a->top != -1)
	{
		if (is_sorted_a(s_a) == true)
			break;
		pivot = get_mid_point(s_a, 0, s_a->top);
		chunks++;
		push_to_b(s_a, s_b, pivot);
	}
}

void	push_to_b(stack *s_a, stack *s_b, int pivot)
{
	while (s_a->top >= s_a->top / 2)
	{
		while (s_a->items[s_a->top] < pivot)
			pb(s_a, s_b);
		if (s_a->items[0] < pivot)
		{
			rra(s_a);
			pb(s_a, s_b);
		}
		else
			ra(s_a);
	}
	if (s_a->items[1] > s_a->items[0])
			sa(s_a);
}

void	push_back_to_a(stack *s_a, stack *s_b)
{

}
