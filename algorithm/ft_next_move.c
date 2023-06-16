/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:32:44 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/16 16:18:34 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	next_rotate(stack *s_a, int pivot)
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
		return (true);
	return (false);
}

void	next_swap(stack *s_a, stack *s_b, int guard)
{
	if (s_a->items[s_a->top] > s_a->items[s_a->top - 1])
	{
		if ((ft_biggest(s_b, s_b->items[s_b->top - 1]) == true && s_b->top != 0) || \
		(ft_second_biggest(s_b, s_b->items[s_b->top - 1]) == true && guard == 0))
			ss(s_a, s_b);
		else
			sa(s_a);
	}
	else if ((ft_biggest(s_b, s_b->items[s_b->top - 1]) == true && \
	s_b->top != 0) || \
	(ft_second_biggest(s_b, s_b->items[s_b->top - 1]) == true && \
	guard == 0))
		sb(s_b);
	else
		return ;
}

