/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:48:19 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/21 17:16:59 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <fcntl.h>

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
		return (free(s_a->items), free(s_a), 1);
	if (get_input(s_a, s_b) == -1)
		return (term_strct_bonus(s_a, s_b), write(2, "Error\n", 6));
	stack_visualizer(s_a, s_b);
	ft_printf("Moves: %d\n", s_a->move_counter);
	if ((is_sorted_a(s_a) && s_b->top == -1) || s_a->size == 1)
		return (term_strct_bonus(s_a, s_b), ft_printf("OK\n"), 0);
	ft_printf("KO\n");
	term_strct_bonus(s_a, s_b);
	return (0);
}

int	get_input(t_stack *s_a, t_stack *s_b)
{
	char	*line;
	char	*buffer;

	s_a->move_counter = 0;
	buffer = get_next_line(0, &line);
	while (line != NULL)
	{
		if (rule_err_check(line) == false)
			return (free(buffer), free(line), -1);
		do_operation(s_a, s_b, line);
		s_a->move_counter++;
		free(line);
		buffer = get_next_line(0, &line);
	}
	free(line);
	return (0);
}

void	do_operation(t_stack *s_a, t_stack *s_b, char *line)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		ra_bonus(s_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb_bonus(s_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr_bonus(s_a, s_b);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		sa_bonus(s_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb_bonus(s_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss_bonus(s_a, s_b);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb_bonus(s_b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra_bonus(s_a);
	else if (ft_strncmp(line, "rrr\n", 3) == 0)
		rrr_bonus(s_a, s_b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa_bonus(s_a, s_b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb_bonus(s_a, s_b);
}
