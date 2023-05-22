/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:32:11 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/22 19:22:35 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

stack	*strct_init(char **numbrs)
{
	int		i;
	stack	*s;

	i = 0;
	s = malloc(sizeof(stack));
	if (!a)
		return (NULL);
	s->size = get_stack_size(numbrs);
	s->items = malloc(sizeof(int) * s->size);
	if (!s->items)
	{
		free(s);
		return (NULL);
	}
	while (numbrs[i])
	{
		s->items[i] = ft_atoi(numbrs[i]);
		i++;
	}
	return (s);
}

int	get_stack_size(char	**numbrs)
{
	int	i;

	i = 0;
	while (numbrs[i])
		i++;
	return (i);
}
