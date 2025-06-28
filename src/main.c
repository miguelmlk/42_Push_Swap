/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:00:27 by mimalek           #+#    #+#             */
/*   Updated: 2025/03/05 12:07:43 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	ft_free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int	ft_count_num(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	ft_handle_single_arg(char **argv, char ***split_arg,
	char ***new_argv, int *argc)
{
	int	i;

	*split_arg = ft_split(argv[1], ' ');
	if (!*split_arg)
		return (0);
	*argc = ft_count_num(*split_arg) + 1;
	*new_argv = malloc(sizeof(char *) * (*argc + 1));
	if (!*new_argv)
		return (ft_free_split(*split_arg), 0);
	(*new_argv)[0] = argv[0];
	i = 0;
	while (i < *argc - 1)
	{
		(*new_argv)[i + 1] = (*split_arg)[i];
		i++;
	}
	(*new_argv)[*argc] = NULL;
	return (1);
}

int	ft_validate_and_prepare(int	*argc, char ***argv, char ***split_arg)
{
	*split_arg = NULL;
	if (*argc < 2 || (*argc == 2 && (!(*argv)[1] || !(*argv)[1][0])))
		return (0);
	if (*argc == 2)
	{
		if (!ft_handle_single_arg(*argv, split_arg, argv, argc))
			return (0);
	}
	if (!ft_error(*argc, *argv))
	{
		if (*split_arg)
			ft_free_split(*split_arg);
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_arg;
	int		result;

	a = NULL;
	b = NULL;
	if (!ft_validate_and_prepare(&argc, &argv, &split_arg))
		return (1);
	a = ft_init_stack(argc, argv);
	if (!a)
	{
		if (split_arg)
			ft_free_split(split_arg);
		return (1);
	}
	result = ft_prepare_sorting(&a, &b);
	ft_free_stack(a);
	ft_free_stack(b);
	if (split_arg)
		ft_free_split(split_arg);
	return (result);
}
