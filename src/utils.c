/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:32:11 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/19 13:30:52 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
			str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

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

	i = 0;
	while (numbrs[i])
		i++;
	return (i - 1);
}

int	get_stack_size_str(char **numbrs)
{
	int	i;

	i = 0;
	while (numbrs[i])
		i++;
	return (i);
}

void	push(t_stack *s, int data)
{
	if (s->top == s->size - 1)
		return ;
	s->top++;
	s->items[s->top] = data;
}
