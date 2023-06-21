/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:15:25 by njantsch          #+#    #+#             */
/*   Updated: 2023/06/21 13:35:52 by njantsch         ###   ########.fr       */
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
	int	move_counter;
}	t_stack;

t_stack	*strct_init_a(char **numbrs);
t_stack	*strct_init_str_a(char **numbrs);
t_stack	*strct_init_b(t_stack *s_a);
int		get_stack_size(char	**numbrs);
int		get_stack_size_str(char **numbrs);
void	terminate_strcts(t_stack *s_a, t_stack *s_b);

bool	ft_err_checking(int ac, char **av);
bool	ft_checks(int args, char **num);
bool	ft_dups(char **num);
bool	ft_not_num(char **num);
bool	ft_not_int(char **num);

void	free_prev_alloc(char **buff);
long	ft_atol(char *str);

void	push(t_stack *s, int data);

void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *s_a, t_stack *s_b);

void	pa(t_stack *s_a, t_stack *s_b);
void	pb(t_stack *s_a, t_stack *s_b);

void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s_a, t_stack *s_b);

void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *s_a, t_stack *s_b);

void	stack_visualizer(t_stack *s_a, t_stack *s_b);

int		quicksort(t_stack *s, int *arr, int length);
void	quicksort_rec(int *arr, int low, int high);
void	ft_swap(int *a, int *b);
int		partition(int *arr, int low, int high);

bool	is_sorted_a(t_stack *s);
bool	is_sorted_b(t_stack *s);
bool	is_chunk_finished(t_stack *s, int pivot);
bool	ft_biggest(t_stack *s, int item);
bool	ft_second_biggest(t_stack *s, int item);

void	ft_sort(t_stack *s_a, t_stack *s_b);
int		get_mid_point(t_stack *s, int start, int end);
void	push_to_b(t_stack *s_a, t_stack *s_b, int pivot);
void	push_back_to_a(t_stack *s_a, t_stack *s_b, int guard);

void	which_rotate_b(t_stack *s_b, int guard);
void	which_rotate_a(t_stack *s_a, int pivot);
void	rotate_func(t_stack *s_a, t_stack *s_b);
void	sort_three(t_stack *s);
void	sort_five(t_stack *s_a, t_stack *s_b);
bool	next_rotate(t_stack *s_a, int pivot);
void	next_swap(t_stack *s_a, t_stack *s_b, int guard);

// bonus functions
bool	rule_err_check(char *line);
int		get_input(t_stack *s_a, t_stack *s_b);
void	do_operation(t_stack *s_a, t_stack *s_b, char *line);
void	term_strct_bonus(t_stack *s_a, t_stack *s_b);

//bonus rules
void	sa_bonus(t_stack *s);
void	sb_bonus(t_stack *s);
void	ss_bonus(t_stack *s_a, t_stack *s_b);

void	pa_bonus(t_stack *s_a, t_stack *s_b);
void	pb_bonus(t_stack *s_a, t_stack *s_b);

void	ra_bonus(t_stack *s);
void	rb_bonus(t_stack *s);
void	rr_bonus(t_stack *s_a, t_stack *s_b);

void	rra_bonus(t_stack *s);
void	rrb_bonus(t_stack *s);
void	rrr_bonus(t_stack *s_a, t_stack *s_b);

#endif
