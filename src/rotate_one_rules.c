/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_one_rules.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:59:48 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/23 17:59:00 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(stack *s)
{
	int	tmp;
	int	i;

	if (s->top < 1)
		return;
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

void	rb(stack *s)
{
	int	tmp;
	int	i;

	if (s->top < 1)
		return;
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
