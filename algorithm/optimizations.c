/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:49:26 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/09 18:11:18 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	which_rotate_b(stack *s_b)
{
	int	i;

	i = 0;
	while (i <= s_b->top / 2)
	{
		if (ft_smallest(s_b, s_b->items[i]) == true)
		{
			rrb(s_b);
			return ;
		}
		i++;
	}
	while (i <= s_b->top)
	{
		if (ft_smallest(s_b, s_b->items[i]) == true)
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
	int	moves1;
	int	moves2;
	int	count;

	i = 0;
	moves1 = 0;
	moves2 = 0;
	while (i < s_a->top / 2)
	{
		if (s_a->items[i] < pivot)
		{
			moves1 = i;
			break ;
		}
		i++;
	}
	i = s_a->top;
	count = 0;
	while (i > s_a->top / 2)
	{
		if (s_a->items[i] < pivot)
		{
			moves2 = count;
			break ;
		}
		count++;
		i--;
	}
	if ((moves2 < moves1 && moves2 != 0) || moves1 == 0 \
	|| moves1 == moves2)
		ra(s_a);
	if ((moves1 < moves2 && moves1 != 0) || moves2 == 0)
		rra(s_a);
}
