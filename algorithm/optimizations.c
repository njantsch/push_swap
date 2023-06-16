/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:49:26 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/16 16:10:33 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	which_rotate_b(stack *s_b, int guard)
{
	int	i;

	i = 0;
	while (i <= s_b->top / 2)
	{
		if (ft_biggest(s_b, s_b->items[i]) == true || \
		(ft_second_biggest(s_b, s_b->items[i]) == true \
		&& guard == 0))
		{
			rrb(s_b);
			return ;
		}
		i++;
	}
	while (i <= s_b->top)
	{
		if (ft_biggest(s_b, s_b->items[i]) == true || \
		(ft_second_biggest(s_b, s_b->items[i]) == true \
		&& guard == 0))
		{
			rb(s_b);
			return ;
		}
		i++;
	}
}

void	which_rotate_a(stack *s_a, int pivot)
{
	int	i;

	i = 0;
	s_a->moves1 = 2;
	s_a->moves2 = 1;
	while (i < s_a->top / 2)
	{
		if (s_a->items[i] <= pivot)
			break ;
		s_a->moves1++;
		i++;
	}
	i = s_a->top;
	while (i > s_a->top / 2)
	{
		if (s_a->items[i] <= pivot)
			break ;
		s_a->moves2++;
		i--;
	}
	if (s_a->moves2 <= s_a->moves1)
		ra(s_a);
	if (s_a->moves1 < s_a->moves2)
		rra(s_a);
}

void	sort_three(stack *s)
{
	while (is_sorted_a(s) == false)
	{
		if (s->items[0] > s->items[2] && s->items[2] > s->items[1])
			sa(s);
		else if (s->items[2] > s->items[1] && s->items[1] > s->items[0])
		{
			sa(s);
			rra(s);
		}
		else if (s->items[2] > s->items[0] && s->items[0] > s->items[1])
			ra(s);
		else if (s->items[1] > s->items[0] && s->items[0] > s->items[2])
		{
			sa(s);
			ra(s);
		}
		else
			rra(s);
	}
}

void	sort_five(stack *s_a, stack *s_b)
{
	if (s_a->top == 4)
	{
		while (is_chunk_finished(s_a, s_a->items[s_a->top]) == false)
		{
			if (is_chunk_finished(s_a, s_a->items[0]) == true
			|| is_chunk_finished(s_a, s_a->items[1]) == true)
				rra(s_a);
			else
				ra(s_a);
		}
		pb(s_a, s_b);
		while (ft_biggest(s_a, s_a->items[s_a->top]) == false)
		{
			if (ft_biggest(s_a, s_a->items[0]) == true
			|| ft_biggest(s_a, s_a->items[1]) == true)
				rra(s_a);
			else
				ra(s_a);
		}
		pb(s_a, s_b);
		sort_three(s_a);
		pa(s_a, s_b);
		ra(s_a);
		pa(s_a, s_b);
	}
	else if (s_a->top == 3)
	{
		while (is_chunk_finished(s_a, s_a->items[s_a->top]) == false)
			ra(s_a);
		pb(s_a, s_b);
		sort_three(s_a);
		pa(s_a, s_b);
	}
	else if (s_a->top == 2)
		sort_three(s_a);
}
