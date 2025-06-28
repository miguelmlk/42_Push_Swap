/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:54:26 by mimalek           #+#    #+#             */
/*   Updated: 2025/03/10 13:21:02 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_error(int argc, char **argv)
{
	if (!ft_input_check(argc, argv))
		return (0);
	if (!ft_doubled(argc, argv))
		return (0);
	return (1);
}

int	ft_doubled(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_input_check(int argc, char **argv)
{
	int		i;
	int		j;
	long	num;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0' && argv[i][j])
			return (0);
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}
