/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:15:25 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/13 12:12:33 by njantsch         ###   ########.fr       */
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
	int	moves1;
	int	moves2;
	int	median;
}	stack;

stack	*strct_init_a(char **numbrs);
stack	*strct_init_str_a(char **numbrs);
stack	*strct_init_b(stack *s_a);
int		get_stack_size(char	**numbrs);
int		get_stack_size_str(char **numbrs);

bool	ft_err_checking(int	ac, char **av);
bool	ft_checks(int args, char **num);
bool	ft_dups(char **num);
bool	ft_not_num(char **num);
bool	ft_not_int(char **num);
bool	ft_is_sorted(char **num);

void	free_prev_alloc(char **buff);
long	ft_atoi_long(char *str);

void	push(stack *s, int data);

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

void	stack_visualizer(stack *s_a, stack *s_b);

int		quicksort(stack *s, int *arr, int length);
void	quicksort_rec(int *arr, int low, int high);
void	ft_swap(int *a, int *b);
int		partition(int *arr, int low, int high);

bool	is_sorted_a(stack *s);
bool	is_sorted_b(stack *s);
bool	is_chunk_finished(stack *s, int pivot);
bool	ft_smallest(stack *s, int pivot);

void	ft_sort(stack *s_a, stack *s_b);
int		get_mid_point(stack *s, int start, int end);
int		push_to_b(stack *s_a, stack *s_b, int pivot, int median);
void	push_back_to_a(stack *s_a, stack *s_b, int pivot, int chunk);

void	which_rotate_b(stack *s_b);
void	which_rotate_a(stack *s_a, int pivot);
void	sort_three(stack *s);
void	sort_five(stack *s_a, stack *s_b);
bool	next_rotate(stack *s_a, int pivot);

#endif
