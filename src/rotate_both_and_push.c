/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both_and_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:00:13 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/19 12:24:45 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr(t_stack *s_a, t_stack *s_b)
{
	int	tmp;
	int	i;

	if (s_a->top < 1 || s_b->top < 1)
		return ;
	i = s_a->top;
	tmp = s_a->items[s_a->top];
	while (i >= 1)
	{
		s_a->items[i] = s_a->items[i - 1];
		i--;
	}
	s_a->items[0] = tmp;
	i = s_b->top;
	tmp = s_b->items[s_b->top];
	while (i >= 1)
	{
		s_b->items[i] = s_b->items[i - 1];
		i--;
	}
	s_b->items[0] = tmp;
	ft_printf("rr\n");
}

void	rrr(t_stack *s_a, t_stack *s_b)
{
	int	tmp;
	int	i;

	if (s_a->top < 1 || s_b->top < 1)
		return ;
	tmp = s_a->items[0];
	i = 0;
	while (i < s_a->top)
	{
		s_a->items[i] = s_a->items[i + 1];
		i++;
	}
	s_a->items[s_a->top] = tmp;
	i = 0;
	tmp = s_b->items[0];
	while (i < s_b->top)
	{
		s_b->items[i] = s_b->items[i + 1];
		i++;
	}
	s_b->items[s_b->top] = tmp;
	ft_printf("rrr\n");
}

void	pa(t_stack *s_a, t_stack *s_b)
{
	int	tmp;

	if (s_a->top == s_a->size -1 || s_b->top == -1)
		return ;
	tmp = s_b->items[s_b->top];
	s_b->top--;
	push(s_a, tmp);
	ft_printf("pa\n");
}

void	pb(t_stack *s_a, t_stack *s_b)
{
	int	tmp;

	if (s_b->top == s_b->size -1 || s_a->top == -1)
		return ;
	tmp = s_a->items[s_a->top];
	s_a->top--;
	push(s_b, tmp);
	ft_printf("pb\n");
}
