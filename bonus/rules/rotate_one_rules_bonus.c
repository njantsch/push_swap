/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_one_rules_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:59:48 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/20 14:04:11 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra_bonus(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->top < 1)
		return ;
	i = s->top;
	tmp = s->items[s->top];
	while (i >= 1)
	{
		s->items[i] = s->items[i - 1];
		i--;
	}
	s->items[0] = tmp;
}

void	rb_bonus(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->top < 1)
		return ;
	i = s->top;
	tmp = s->items[s->top];
	while (i >= 1)
	{
		s->items[i] = s->items[i - 1];
		i--;
	}
	s->items[0] = tmp;
}

void	rra_bonus(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->top < 1)
		return ;
	tmp = s->items[0];
	i = 0;
	while (i < s->top)
	{
		s->items[i] = s->items[i + 1];
		i++;
	}
	s->items[s->top] = tmp;
}

void	rrb_bonus(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->top < 1)
		return ;
	tmp = s->items[0];
	i = 0;
	while (i < s->top)
	{
		s->items[i] = s->items[i + 1];
		i++;
	}
	s->items[s->top] = tmp;
}
