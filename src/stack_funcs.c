/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:33:14 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/24 16:17:08 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

stack	*strct_init_a(char **numbrs)
{
	int		i;
	stack	*s;

	s = malloc(sizeof(stack));
	if (!s)
		return (NULL);
	s->top = -1;
	s->size = get_stack_size(numbrs);
	i = s->size + 1;
	s->items = malloc(sizeof(int) * s->size);
	if (!s->items)
	{
		free(s);
		return (NULL);
	}
	while (i > 1)
	{
		s->top++;
		s->items[s->top] = ft_atoi(numbrs[i - 1]);
		i--;
	}
	return (s);
}

stack	*strct_init_str_a(char **numbrs)
{
	int		i;
	char	**buff;
	stack	*s;

	s = malloc(sizeof(stack));
	if (!s)
		return (NULL);
	s->top = -1;
	buff = ft_split(numbrs[1], ' ');
	s->size = get_stack_size_str(buff);
	i = s->size;
	s->items = malloc(sizeof(int) * s->size);
	if (!s->items)
	{
		free(s);
		return (NULL);
	}
	while (i > 0)
	{
		s->top++;
		s->items[s->top] = ft_atoi(buff[i - 1]);
		i--;
	}
	free_prev_alloc(buff);
	return (s);
}

stack	*strct_init_b(stack *s_a)
{
	stack *s_b;

	s_b = malloc(sizeof(stack));
	if (!s_b)
		return (NULL);
	s_b->top = -1;
	s_b->size = s_a->size;
	s_b->items = malloc(sizeof(int) * s_b->size);
	if (!s_b)
	{
		free(s_b);
		return (NULL);
	}
	return (s_b);
}
