/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:13:26 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/12 15:53:53 by njantsch         ###   ########.fr       */
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
	int pValue;
	int	i;
	int	j;

	pValue = arr[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (arr[j] < pValue)
		{
			ft_swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	ft_swap(&arr[i], &arr[high]);
	return (i);
}

int	quicksort(stack *s, int *arr, int length)
{
	int	mid_value;

	quicksort_rec(arr, 0, length - 1);
	// ft_printf("length: %d\n", length);
	if (length <= 50)
	{
		mid_value = arr[length / 3];
		s->median = arr[length / 6];
	}
	else if (length <= 100)
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
	int	pIndex;

	if (low < high)
	{
		pIndex = partition(arr, low, high);
		quicksort_rec(arr, low, pIndex - 1);
		quicksort_rec(arr, pIndex + 1, high);
	}
}
