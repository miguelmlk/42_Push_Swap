/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:16:36 by mimalek           #+#    #+#             */
/*   Updated: 2025/03/04 12:01:42 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = get_last(*stack);
	last->previous->next = NULL;
	last->next = *stack;
	last->previous = NULL;
	*stack = last;
	last->next->previous = last;
}

void	ft_rra(t_stack **a, int j)
{
	rev_rotate(a);
	if (j == 0)
		ft_printf("rra\n");
}

void	ft_rrb(t_stack **b, int j)
{
	rev_rotate(b);
	if (j == 0)
		ft_printf("rrb\n");
}

void	ft_rrr(t_stack **a, t_stack **b, int j)
{
	rev_rotate(a);
	rev_rotate(b);
	if (j == 0)
		ft_printf("rrr\n");
}
