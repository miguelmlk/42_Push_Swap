/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:42:14 by mimalek           #+#    #+#             */
/*   Updated: 2025/03/04 15:19:34 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	long	num;
	int		minus;

	i = 0;
	minus = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * minus);
}

int	ft_prepare_sorting(t_stack **a, t_stack **b)
{
	if (!ft_check_sorted(*a))
	{
		if (ft_stack_len(*a) == 2)
			ft_sa(a, 0);
		else if (ft_stack_len(*a) == 3)
			ft_sort_3(a);
		else
			ft_turk(a, b);
	}
	return (1);
}
