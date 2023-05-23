/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:12:40 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/23 14:49:49 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	stack	*s_a;
	stack	*s_b;

	if (ac < 2)
		return (1);
	if (ft_checks(av) == false)
		return (ft_printf("Error\n"));
	if (ac > 2)
		s_a = strct_init_a(av);
	else if (ac == 2)
		s_a = strct_init_str_a(av);
	if (!s_a)
		return (ft_printf("Error creating struct\n"));
	s_b = strct_init_b(s_a);
	if (!s_b)
		return (ft_printf("Error creating struct\n"));
}