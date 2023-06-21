/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:33:14 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/20 17:44:32 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*strct_init_a(char **numbrs)
{
	int		i;
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = -1;
	s->size = get_stack_size(numbrs);
	i = s->size + 1;
	s->median = 0;
	s->items = malloc(sizeof(int) * s->size);
	if (!s->items)
		return (free(s), NULL);
	while (i > 1)
	{
		s->top++;
		s->items[s->top] = ft_atoi(numbrs[i - 1]);
		i--;
	}
	return (s);
}

t_stack	*strct_init_str_a(char **numbrs)
{
	int		i;
	char	**buff;
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = -1;
	buff = ft_split(numbrs[1], ' ');
	s->size = get_stack_size_str(buff);
	i = s->size;
	s->median = 0;
	s->items = malloc(sizeof(int) * s->size);
	if (!s->items)
		return (free(s), NULL);
	while (i > 0)
	{
		s->top++;
		s->items[s->top] = ft_atoi(buff[i - 1]);
		i--;
	}
	free_prev_alloc(buff);
	return (s);
}

t_stack	*strct_init_b(t_stack *s_a)
{
	t_stack	*s_b;

	s_b = malloc(sizeof(t_stack));
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

void	stack_visualizer(t_stack *s_a, t_stack *s_b)
{
	int	i;
	int	j;

	i = s_a->top;
	j = s_b->top;
	ft_printf("\n");
	while (i >= 0 || j >= 0)
	{
		if (i == j)
		{
			ft_printf("%d        ", s_a->items[i--]);
			ft_printf("%d\n", s_b->items[j--]);
		}
		else if (i > j)
			ft_printf("%d\n", s_a->items[i--]);
		else if (i < j)
			ft_printf("         %d\n", s_b->items[j--]);
	}
	ft_printf("a--------b---------\n");
}
