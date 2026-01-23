/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 21:33:51 by dbobrov           #+#    #+#             */
/*   Updated: 2026/01/21 21:33:51 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_index;
	int				cost_a;
	int				cost_b;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

void				sa(t_stack **stack);
void				sb(t_stack **stack);
void				ss(t_stack **stack_a, t_stack **stack_b);

void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);

void				ra(t_stack **stack);
void				rb(t_stack **stack);
void				rr(t_stack **stack_a, t_stack **stack_b);

void				rra(t_stack **stack);
void				rrb(t_stack **stack);
void				rrr(t_stack **stack_a, t_stack **stack_b);

void				stack_add_front(t_stack **stack, t_stack *elem);
void				stack_add_back(t_stack **stack, t_stack *elem);
t_stack				*stack_new(int value);

int					stack_size(t_stack *stack);
void				stack_clear(t_stack **stack);
void				stack_set_index(t_stack **stack);
void				stack_set_pos(t_stack *stack);

t_stack				*stack_last(t_stack *stack);
void				set_target_node(t_stack *a, t_stack *b);
void				stack_set_costs(t_stack *a, t_stack *b);

#endif
