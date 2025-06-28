/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:15:06 by mimalek           #+#    #+#             */
/*   Updated: 2025/02/25 12:46:12 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sa(t_stack **a, int j)
{
	t_stack	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->previous = tmp;
	(*a)->next = tmp;
	tmp->previous = *a;
	(*a)->previous = NULL;
	if (j == 0)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **b, int j)
{
	t_stack	*tmp;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	if ((*b)->next)
		(*b)->next->previous = tmp;
	(*b)->next = tmp;
	tmp->previous = *b;
	(*b)->previous = NULL;
	if (j == 0)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b, int j)
{
	ft_sa(a, 1);
	ft_sb(b, 1);
	if (j == 0)
		write(1, "ss\n", 3);
}
