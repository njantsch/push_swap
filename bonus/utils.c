/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:05:04 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/21 14:28:56 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	term_strct_bonus(t_stack *s_a, t_stack *s_b)
{
	free(s_a->items);
	free(s_b->items);
	free(s_a);
	free(s_b);
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
