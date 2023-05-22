/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:15:25 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/22 19:24:02 by njantsch         ###   ########.fr       */
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
}	stack;

stack_a	*strct_init(char **numbrs);
int		get_stack_size(char	**numbrs);
bool	ft_checks(char **num);
bool	ft_dups(char **num);
bool	ft_not_num(char **num);
bool	ft_not_int(char **num);

#endif
