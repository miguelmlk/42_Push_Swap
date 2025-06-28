/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:53:20 by mimalek           #+#    #+#             */
/*   Updated: 2025/02/24 18:06:20 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rotation_both(t_stack **a, t_stack **b, t_stack *next_node)
{
	while (*b != next_node->target_node && *a != next_node)
		ft_rr(a, b, 0);
	current_indices(*a);
	current_indices(*b);
}

void	ft_rev_rotation_both(t_stack **a, t_stack **b, t_stack *next_node)
{
	while (*b != next_node->target_node && *a != next_node)
		ft_rrr(a, b, 0);
	current_indices(*a);
	current_indices(*b);
}
