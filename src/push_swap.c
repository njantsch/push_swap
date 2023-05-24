/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:12:40 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/24 17:55:30 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	stack	*s_a;
	stack	*s_b;

	if (ac < 2)
		return (1);
	if (ft_checks(ac, av) == false)
		return (ft_printf("Error\n"));
	if (ac > 2)
		s_a = strct_init_a(av);
	else
		s_a = strct_init_str_a(av);
	if (!s_a)
		return (ft_printf("Error creating struct\n"));
	s_b = strct_init_b(s_a);
	if (!s_b)
		return (ft_printf("Error creating struct\n"));
	free(s_a);
	free(s_b);
	return (0);
}

// void	stack_visualizer(stack *s_a, stack *s_b)
// {
// 	int	i;
// 	int	j;

// 	i = s_a->top;
// 	j = s_b->top;
// 	while (i >= 0 || j >= 0)
// 	{
// 		if (i == j)
// 		{
// 			ft_printf("%d        ", s_a->items[i]);
// 			ft_printf("%d\n", s_b->items[j]);
// 			i--;
// 			j--;
// 		}
// 		else if (i > j)
// 		{
// 			ft_printf("%d\n", s_a->items[i]);
// 			i--;
// 		}
// 		else if (i < j)
// 		{
// 			ft_printf("         %d\n", s_b->items[j]);
// 			j--;
// 		}
// 	}
// 	ft_printf("a--------b---------\n");
// }
