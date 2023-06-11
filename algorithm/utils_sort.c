/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:44:26 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/11 16:23:47 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted_a(stack *s)
{
	int	i;

	i = s->top;
	if (s->top == 0)
		return (false);
	while (i >= 0)
	{
		if (s->items[i] > s->items[i - 1] && i - 1 != -1)
			return (false);
		i--;
	}
	return (true);
}

bool	is_sorted_b(stack *s)
{
	int	i;

	i = s->top;
	if (s->top == 0)
		return (false);
	while (i >= 0)
	{
		if (s->items[i] < s->items[i - 1] && i - 1 != -1)
			return (false);
		i--;
	}
	return (true);
}

bool	is_chunk_finished(stack *s, int pivot)
{
	int	i;

	i = 0;
	while (i <= s->top)
	{
		if (s->items[i] < pivot)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_smallest(stack *s, int pivot)
{
	int	i;

	i = 0;
	while (i <= s->top)
	{
		if (s->items[i] > pivot)
			return (false);
		i++;
	}
	return (true);
}
