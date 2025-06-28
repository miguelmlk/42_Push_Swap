/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:59:08 by mimalek           #+#    #+#             */
/*   Updated: 2025/03/04 14:48:26 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_init_stack(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		i;
	int		j;

	if (argc < 2)
		return (NULL);
	j = 1;
	i = 2;
	stack = ft_new_node(ft_atoi(argv[1]), 0);
	if (!stack)
		return (NULL);
	tmp = stack;
	while (i < argc)
	{
		tmp->next = ft_new_node(ft_atoi(argv[i]), j);
		if (!tmp->next)
			return (ft_free_stack(stack), NULL);
		tmp->next->previous = tmp;
		tmp = tmp -> next;
		i++;
		j++;
	}
	return (stack);
}

t_stack	*ft_new_node(int number, int index)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->number = number;
	node->index = index;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack -> next;
		free(tmp);
	}
}
