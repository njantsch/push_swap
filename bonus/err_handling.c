/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:22:49 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/21 14:22:37 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	rule_err_check(char *line)
{
	if (ft_strlen(line) > 4)
		return (false);
	if (ft_strncmp(line, "ra\n", 3) == 0
		|| ft_strncmp(line, "rb\n", 3) == 0
		|| ft_strncmp(line, "rr\n", 3) == 0
		|| ft_strncmp(line, "rra\n", 4) == 0
		|| ft_strncmp(line, "rrb\n", 4) == 0
		|| ft_strncmp(line, "rrr\n", 4) == 0
		|| ft_strncmp(line, "sa\n", 3) == 0
		|| ft_strncmp(line, "sb\n", 3) == 0
		|| ft_strncmp(line, "pa\n", 3) == 0
		|| ft_strncmp(line, "pb\n", 3) == 0
		|| ft_strncmp(line, "ss\n", 3) == 0)
		return (true);
	return (false);
}

bool	ft_checks(int args, char **num)
{
	if (args < 2)
		return (false);
	if (ft_dups(num) == false)
		return (false);
	if (ft_not_num(num) == false)
		return (false);
	if (ft_not_int(num) == false)
		return (false);
	return (true);
}

bool	ft_dups(char **num)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	while (num[i])
	{
		j = i + 1;
		len = ft_strlen(num[i]);
		if (len == 0)
			return (false);
		while (num[j])
		{
			if (ft_strlen(num[j]) > len)
				len = ft_strlen(num[j]);
			if (ft_strncmp(num[i], num[j], len) == 0 && len != 0)
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
	int	check;

	i = 0;
	while (num[i])
	{
		j = 0;
		check = 0;
		while (num[i][j])
		{
			if ((num[i][j] == '-' || num[i][j] == '+') && check == 0)
			{
				j++;
				check++;
			}
			if (num[i][j] >= '0' && num[i][j] <= '9')
				check++;
			if (num[i][j] < '0' || num[i][j] > '9')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_not_int(char **num)
{
	long	*nums;
	int		i;
	int		len;

	len = 0;
	while (num[len])
		len++;
	nums = malloc(sizeof(long) * len - 1);
	i = 0;
	while (i < len)
	{
		nums[i] = ft_atol(num[i]);
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
