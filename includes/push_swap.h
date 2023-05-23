/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:15:25 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/23 17:10:57 by njantsch         ###   ########.fr       */
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

bool	ft_checks(char **num);
bool	ft_dups(char **num);
bool	ft_not_num(char **num);
bool	ft_not_int(char **num);

void	free_prev_alloc(char **buff);

stack	push(stack *s, int data);
stack	pop(stack *s, int *data);

stack	ft_sa(stack *s);
stack	ft_sb(stack *s);
stack	ft_ss(stack *s_a, stack *s_b);

stack	ft_pa();
stack	ft_pb();

stack	ft_ra();
stack	ft_rb();
stack	ft_rr();

stack	ft_rra();
stack	ft_rrb();
stack	ft_rrr();

#endif
