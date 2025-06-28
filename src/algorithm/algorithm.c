/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:42:01 by mimalek           #+#    #+#             */
/*   Updated: 2025/03/04 11:52:07 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort(int argc, t_stack *a, t_stack *b)
{
	if (argc == 2)
		return ;
	else if (argc == 3)
		ft_sa(&a, 0);
	else if (argc == 4)
		ft_sort_3(&a);
	else if (argc > 4)
		ft_turk(&a, &b);
}

void	ft_turk(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_stack_len(*a);
	if (len-- > 3 && !ft_check_sorted(*a))
		ft_pb(a, b, 0);
	if (len-- > 3 && !ft_check_sorted(*a))
		ft_pb(a, b, 0);
	while (len-- > 3 && !ft_check_sorted(*a))
	{
		init_nodes_a(*a, *b);
		ft_to_b(a, b);
	}
	ft_sort_3(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		ft_to_a(a, b);
	}
	current_indices(*a);
	ft_small_to_top(a);
}

void	ft_to_b(t_stack **a, t_stack **b)
{
	t_stack	*next_node;

	next_node = ft_get_next_move(*a);
	if (next_node->above_median == next_node->target_node->above_median)
	{
		if (next_node->above_median)
			ft_rotation_both(a, b, next_node);
		else
			ft_rev_rotation_both(a, b, next_node);
	}
	ft_before_push(a, next_node, 1);
	ft_before_push(b, next_node->target_node, 2);
	ft_pb(a, b, 0);
}

void	ft_to_a(t_stack **a, t_stack **b)
{
	ft_before_push(a, (*b)->target_node, 1);
	ft_pa(a, b, 0);
}

t_stack	*get_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
