/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_assign_targets.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:05:54 by mimalek           #+#    #+#             */
/*   Updated: 2025/03/04 14:30:47 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	assign_target_a(t_stack *a, t_stack *b)
{
	t_stack	*tmp_b;
	t_stack	*target_node;
	long	current;
	t_stack	*max_b;

	if (!a || !b)
		return ;
	max_b = find_max(b);
	while (a)
	{
		tmp_b = b;
		current = LONG_MIN;
		target_node = max_b;
		while (tmp_b)
		{
			if (tmp_b->number < a->number && tmp_b->number > current)
			{
				target_node = tmp_b;
				current = tmp_b->number;
			}
			tmp_b = tmp_b->next;
		}
		a->target_node = target_node;
		a = a->next;
	}
}

void	assign_target_b(t_stack *a, t_stack *b)
{
	t_stack	*tmp_a;
	t_stack	*target_node;
	long	current;
	t_stack	*min_a;

	if (!a || !b)
		return ;
	min_a = find_min(a);
	while (b)
	{
		tmp_a = a;
		current = LONG_MAX;
		target_node = min_a;
		while (tmp_a)
		{
			if (tmp_a->number > b->number && tmp_a->number < current)
			{
				target_node = tmp_a;
				current = tmp_a->number;
			}
			tmp_a = tmp_a->next;
		}
		b->target_node = target_node;
		b = b->next;
	}
}
