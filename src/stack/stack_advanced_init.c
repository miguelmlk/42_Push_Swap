/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_advanced_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:02:57 by mimalek           #+#    #+#             */
/*   Updated: 2025/03/04 13:40:00 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_indices(a);
	current_indices(b);
	assign_target_a(a, b);
	ft_assign_costs(a, b);
	ft_assign_next_move(a);
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	current_indices(a);
	current_indices(b);
	assign_target_b(a, b);
}

void	current_indices(t_stack *stack)
{
	int		i;
	int		median;
	t_stack	*current;

	i = 0;
	if (!stack)
		return ;
	median = ft_stack_len(stack) / 2;
	current = stack;
	while (current)
	{
		current->index = i;
		current->above_median = (i <= median);
		current = current->next;
		i++;
	}
}

void	ft_assign_costs(t_stack *a, t_stack *b)
{
	int		a_len;
	int		b_len;

	a_len = ft_stack_len(a);
	b_len = ft_stack_len(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_median))
			a->cost = a_len - a->index;
		if (a->target_node->above_median)
			a->cost += a->target_node->index;
		else
			a->cost += b_len - (a->target_node->index);
		a = a->next;
	}
}

void	ft_assign_next_move(t_stack *stack)
{
	t_stack	*next_node;
	long	value;

	if (!stack)
		return ;
	next_node = NULL;
	value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < value)
		{
			value = stack->cost;
			next_node = stack;
		}
		stack = stack->next;
	}
	if (next_node)
		next_node->next_move = true;
}
