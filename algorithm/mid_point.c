/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:13:26 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/19 12:33:18 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int *arr, int low, int high)
{
	int	pivot_value;
	int	i;
	int	j;

	pivot_value = arr[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot_value)
		{
			ft_swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	ft_swap(&arr[i], &arr[high]);
	return (i);
}

int	quicksort(t_stack *s, int *arr, int length)
{
	int	mid_value;

	quicksort_rec(arr, 0, length - 1);
	if (length <= 120)
	{
		mid_value = arr[length / 3];
		s->median = arr[length / 6];
	}
	else if (length <= 240)
	{
		mid_value = arr[length / 4];
		s->median = arr[length / 8];
	}
	else
	{
		mid_value = arr[length / 5];
		s->median = arr[length / 10];
	}
	return (mid_value);
}

void	quicksort_rec(int *arr, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		quicksort_rec(arr, low, pivot_index - 1);
		quicksort_rec(arr, pivot_index + 1, high);
	}
}
