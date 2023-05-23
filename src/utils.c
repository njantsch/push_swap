/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:32:11 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/23 16:45:20 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_prev_alloc(char **buff)
{
	size_t	j;

	j = 0;
	while (buff[j] != NULL)
	{
		free(buff[j]);
		j++;
	}
	free(buff);
}

int	get_stack_size(char	**numbrs)
{
	int	i;

	i = 1;
	while (numbrs[i])
		i++;
	return (i);
}

int	get_stack_size_str(char **numbrs)
{
	int	i;

	i = 0;
	while (numbrs[i])
		i++;
	return (i);
}

void	push(stack *s, int data)
{
	if (s->top == s->size - 1)
		return;
	s->top++;
	s->items[s->top] = data;
}

void	pop(stack *s, int *data)
{
	if (s->top == -1)
		return;
	s->top--;
	*data = s->items[s->top];
}
