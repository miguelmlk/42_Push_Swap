/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:44:21 by mimalek           #+#    #+#             */
/*   Updated: 2025/02/12 15:53:40 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_ra(t_stack **a, int j)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)-> next;
	(*a)-> previous = NULL;
	last = *a;
	while (last -> next)
		last = last->next;
	last->next = tmp;
	tmp -> previous = last;
	tmp -> next = NULL;
	if (j == 0)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b, int j)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)-> next;
	(*b)-> previous = NULL;
	last = *b;
	while (last -> next)
		last = last->next;
	last->next = tmp;
	tmp -> previous = last;
	tmp -> next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b, int j)
{
	ft_ra(a, 1);
	ft_rb(b, 1);
	if (j == 0)
		write(1, "rr\n", 3);
}
