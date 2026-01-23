/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:11:21 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/19 23:11:21 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define CHUNK_CONSTANT 50
# define SORT_COMPLEX_LIMIT 5

# include "algo.h"
# include "ft_printf.h"
# include "libft.h"
# include "stack.h"
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_is_int(char *str);
void	ft_error(void);
bool	ft_in_stack(t_stack *stack, int num);
void	add_in_stack(int argc, char **argv, t_stack **stack, int start);
void	free_stacks(t_stack **stack_a, t_stack **stack_b);
void	parse_single_argument(char *arg, t_stack **stack);

#endif