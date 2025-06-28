/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:07:37 by mimalek           #+#    #+#             */
/*   Updated: 2025/02/25 18:05:07 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort_3(t_stack **a)
{
	t_stack	*biggest;
	t_stack	*first;
	t_stack	*second;

	biggest = find_max(*a);
	first = *a;
	second = first->next;
	if (biggest == first)
		ft_ra(a, 0);
	else if (biggest == second)
		ft_rra(a, 0);
	if ((*a)->number > (*a)->next->number)
		ft_sa(a, 0);
}
