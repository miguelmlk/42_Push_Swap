/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:10:03 by mimalek           #+#    #+#             */
/*   Updated: 2025/02/25 17:52:55 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_before_push(t_stack **stack, t_stack *first_node, int id)
{
	t_stack	*tmp;

	tmp = *stack;
	while (*stack != first_node)
	{
		if (id == 1)
		{
			if (first_node->above_median)
				ft_ra(stack, 0);
			else
				ft_rra(stack, 0);
		}
		else if (id == 2)
		{
			if (first_node->above_median)
				ft_rb(stack, 0);
			else
				ft_rrb(stack, 0);
		}
		if (*stack == tmp)
			break ;
	}
}

t_stack	*ft_get_next_move(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->next_move)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*current;
	t_stack	*result;

	if (!stack)
		return (NULL);
	current = stack;
	result = current;
	while (current != NULL)
	{
		if (current->number > result->number)
			result = current;
		current = current->next;
	}
	return (result);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*current;
	t_stack	*result;

	if (stack == NULL)
		return (NULL);
	current = stack;
	result = current;
	while (current != NULL)
	{
		if (current->number < result->number)
			result = current;
		current = current ->next;
	}
	return (result);
}

void	ft_small_to_top(t_stack **stack)
{
	t_stack	*smallest;

	smallest = find_min(*stack);
	if (!smallest || smallest == *stack)
		return ;
	if (smallest->above_median)
	{
		while (*stack != smallest)
			ft_ra(stack, 0);
	}
	else
	{
		while (*stack != smallest)
			ft_rra(stack, 0);
	}
}
