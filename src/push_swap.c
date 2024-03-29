/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:12:40 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/21 13:51:03 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*s_a;
	t_stack	*s_b;

	if (ac < 2)
		return (0);
	if (ft_err_checking(ac, av) == false)
		return (write(2, "Error\n", 6));
	if (ac > 2)
		s_a = strct_init_a(av);
	else
		s_a = strct_init_str_a(av);
	if (!s_a)
		return (ft_printf("Error creating struct\n"));
	s_b = strct_init_b(s_a);
	if (!s_b)
	{
		free(s_a->items);
		free(s_a);
		return (ft_printf("Error creating struct\n"));
	}
	if (is_sorted_a(s_a) == true)
		return (terminate_strcts(s_a, s_b), 0);
	ft_sort(s_a, s_b);
	terminate_strcts(s_a, s_b);
	return (0);
}

bool	ft_err_checking(int ac, char **av)
{
	char	**buff;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (ac > 2)
	{
		while (av[i])
			i++;
		buff = malloc(sizeof(char *) * i);
		i = 0;
		while (av[j])
			buff[i++] = av[j++];
		buff[i] = NULL;
		if (ft_checks(ac, buff) == false)
			return (free(buff), false);
		return (free(buff), true);
	}
	else
		buff = ft_split(av[1], ' ');
	if (ft_checks(ac, buff) == false)
		return (free_prev_alloc(buff), false);
	return (free_prev_alloc(buff), true);
}

void	terminate_strcts(t_stack *s_a, t_stack *s_b)
{
	free(s_a->items);
	free(s_b->items);
	free(s_a);
	free(s_b);
}
