/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:12:40 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/22 19:25:58 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	stack	*s;

	if (ac < 2)
		return (1);
	if (ft_checks(av) == false)
		return (ft_printf("Error\n"));
	s = strct_init_a(av);
	if (!s)
		return (ft_printf("Error creating struct\n"));
}
