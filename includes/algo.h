/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 23:12:14 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/21 23:12:14 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include <stdbool.h>

void	bubble_sort(int *arr, int size);
void	sort_three(t_stack **a);
bool	is_sorted(t_stack *stack);
void	sort_stack(t_stack **a, t_stack **b);
void	sort_large_stack(t_stack **a, t_stack **b);

t_stack	*get_cheapest(t_stack *b);
void	move_node(t_stack **a, t_stack **b, t_stack *n);

#endif