/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:15:25 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/24 17:55:43 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libs/libs.h"

typedef struct s
{
	int	*items;
	int	size;
	int	top;
}	stack;

stack	*strct_init_a(char **numbrs);
stack	*strct_init_str_a(char **numbrs);
stack	*strct_init_b(stack *s_a);
int		get_stack_size(char	**numbrs);
int		get_stack_size_str(char **numbrs);

bool	ft_checks(int args, char **num);
bool	ft_dups(char **num);
bool	ft_not_num(char **num);
bool	ft_not_int(char **num);
bool	ft_is_sorted(char **num);

void	free_prev_alloc(char **buff);

void	push(stack *s, int data);
void	pop(stack *s, int *data);

void	sa(stack *s);
void	sb(stack *s);
void	ss(stack *s_a, stack *s_b);

void	pa(stack *s_a, stack *s_b);
void	pb(stack *s_a, stack *s_b);

void	ra(stack *s);
void	rb(stack *s);
void	rr(stack *s_a, stack *s_b);

void	rra(stack *s);
void	rrb(stack *s);
void	rrr(stack *s_a, stack *s_b);

// void	stack_visualizer(stack *s_a, stack *s_b);

#endif
