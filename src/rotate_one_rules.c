/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_one_rules.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:59:48 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/19 12:25:10 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *s)
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
	ft_printf("ra\n");
}

void	rb(t_stack *s)
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
	ft_printf("rb\n");
}

void	rra(t_stack *s)
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
	ft_printf("rra\n");
}

void	rrb(t_stack *s)
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
	ft_printf("rrb\n");
}
