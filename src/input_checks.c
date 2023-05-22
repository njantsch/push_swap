/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:01:52 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/22 19:09:51 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_checks(char **num)
{
	if (ft_dups(num) == false)
		return (false);
	if (ft_not_num(num) == false)
		return (false);
	if (ft_not_int(num) == false)
		return (false);
}

bool	ft_dups(char **num)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	while (num[i])
	{
		j = 0;
		len = (size_t)ft_strlen(num[i]);
		while (num[j])
		{
			if (ft_strncmp(num[i], num[j], len) == 0)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_not_num(char **num)
{
	int	i;
	int	j;

	i = 0;
	while (num[i])
	{
		j = 0;
		while (num[i][j])
		{
			if (num[i][0] == '-' || num[i][0] == '+')
				j++;
			if (num[i][j] < '0' && num[i][j] > '9')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_not_int(char **num)
{
	int	*nums;
	int	i;
	int	len;

	len = 0;
	while (num[len])
		len++;
	nums = malloc(sizeof(int) * len);
	i = 0;
	while (i <= len)
	{
		nums[i] = ft_atoi(num[i]);
		if (nums[i] > INT_MAX || nums[i] < INT_MIN)
		{
			free(nums);
			return (false);
		}
		i++;
	}
	free(nums);
	return (true);
}
