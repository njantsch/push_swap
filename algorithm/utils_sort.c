/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:44:26 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/19 12:28:08 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted_a(t_stack *s)
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

bool	is_sorted_b(t_stack *s)
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

bool	is_chunk_finished(t_stack *s, int pivot)
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

bool	ft_biggest(t_stack *s, int item)
{
	int	i;

	i = 0;
	while (i <= s->top)
	{
		if (s->items[i] > item)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_second_biggest(t_stack *s, int item)
{
	int	i;
	int	biggest;
	int	second;

	i = 0;
	biggest = 0;
	while (i <= s->top)
	{
		if (s->items[i] > biggest)
			biggest = s->items[i];
		i++;
	}
	i = 0;
	second = 0;
	while (i <= s->top)
	{
		if (s->items[i] == biggest)
			i++;
		if (s->items[i] > second)
			second = s->items[i];
		i++;
	}
	if (item == second)
		return (true);
	return (false);
}
