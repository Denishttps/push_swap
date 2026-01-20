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

# define SA "sa"
# define SB "sb"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RRA "rra"
# define RRB "rrb"

# define CHUNK_CONSTANT 50
# define SORT_COMPLEX_LIMIT 5

#include "ft_printf/ft_printf.h"

int ft_is_int(char *str);
int ft_error();
int ft_in_stack(int *stack, int size, int num);
int add_in_stack(int argc, char **argv, int *stack);
 

#endif