/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:13:26 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/05 16:05:28 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *arr, int low, int high)
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
			ft_swap(&arr[i], &arr[j])
			i++;
		}
		j++;
	}
	ft_swap(&arr[i], &arr[high]);
	return (i);
}

int	quicksort(int *arr, int length)
{
	int	mid_value

	quicksort_rec(arr, 0, length - 1);
	mid_value = arr[length / 2];
	return (mid_value);
}

static void	quicksort_rec(int *arr, int low, int high)
{
	int	pIndex;

	if (low < high)
	{
		pIndex = partition(arr, low, high);
		quicksort_rec(arr, low, pIndex - 1);
		quicksort_rec(arr, pIndex + 1, high);
	}
}
