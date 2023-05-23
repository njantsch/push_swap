/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:17:47 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/23 17:10:15 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(stack *s)
{
	int	tmp;

	if (s->top < 1)
		return;
	tmp = s->items[s->top];
	s->items[s->top] = s->items[s->top - 1];
	s->items[s->top - 1] = tmp;
	printf("sa\n");
}

void	sb(stack *s)
{
	int	tmp;

	if (s->top < 1)
		return;
	tmp = s->items[s->top];
	s->items[s->top] = s->items[s->top - 1];
	s->items[s->top - 1] = tmp;
	printf("sb\n");
}

void	ss(stack *s_a, stack *s_b)
{
	int	tmp;

	if (s_a->top < 1 || s_b->top < 1)
		return;
	tmp = s_a->items[s_a->top];
	s_a->items[s_a->top] = s_a->items[s_a->top - 1];
	s_a->items[s_a->top - 1] = tmp;
	tmp = s_b->items[s_b->top];
	s_b->items[s_b->top] = s_b->items[s_b->top - 1];
	s_b->items[s_b->top - 1] = tmp;
	ft_printf("ss\n");
}
