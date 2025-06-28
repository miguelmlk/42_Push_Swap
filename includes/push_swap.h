/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:08:59 by mimalek           #+#    #+#             */
/*   Updated: 2025/03/04 15:38:36 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack
{
	long			number;
	long			index;
	int				cost;
	bool			above_median;
	bool			next_move;
	struct s_stack	*next;
	struct s_stack	*previous;
	struct s_stack	*target_node;
}	t_stack;

//		Main Utils

void	ft_free_split(char **args);
int		ft_count_num(char **args);
int		ft_handle_single_arg(char **argv, char ***split_arg,
			char ***new_argv, int *argc);
int		ft_prepare_sorting(t_stack **a, t_stack **b);
int		ft_validate_and_prepare(int	*argc, char ***argv, char ***split_arg);

//		Errors

int		ft_error(int argc, char **argv);
int		ft_doubled(int argc, char **argv);
int		ft_input_check(int argc, char **argv);

//		Operations

//	swap
void	ft_sa(t_stack **a, int j);
void	ft_sb(t_stack **b, int j);
//	push
void	ft_pa(t_stack **a, t_stack **b, int j);
void	ft_pb(t_stack **a, t_stack **b, int j);
//	rotate
void	ft_ra(t_stack **a, int j);
void	ft_rb(t_stack **b, int j);
void	ft_rr(t_stack **a, t_stack **b, int j);
//	reverse rotate
void	ft_rra(t_stack **a, int j);
void	ft_rrb(t_stack **b, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);
//	operation automation
void	ft_rotation_both(t_stack **a, t_stack **b, t_stack *next_node);
void	ft_rev_rotation_both(t_stack **a, t_stack **b, t_stack *next_node);

//		Stack

// Stack_Init.c
t_stack	*ft_init_stack(int argc, char **argv);
t_stack	*ft_new_node(int number, int index);
void	ft_free_stack(t_stack *stack);
// Stack_Advanced_Init.c
void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	current_indices(t_stack *stack);
void	ft_assign_costs(t_stack *a, t_stack *b);
void	ft_assign_next_move(t_stack *stack);
// Stack_Help.c
int		ft_stack_len(t_stack *stack);
void	ft_print_stack(t_stack *stack);
int		ft_check_sorted(t_stack *a);
// Stack_Assign_Targets.c
void	assign_target_a(t_stack *a, t_stack *b);
void	assign_target_b(t_stack *a, t_stack *b);

//		Algorithm

// Algorithm.c
void	ft_sort(int argc, t_stack *a, t_stack *b);
void	ft_turk(t_stack **a, t_stack **b);
void	ft_to_a(t_stack **a, t_stack **b);
void	ft_to_b(t_stack **a, t_stack **b);
t_stack	*get_last(t_stack *stack);
// Sort_3.c
void	ft_sort_3(t_stack **a);
// Algorithm_Help.c
void	ft_before_push(t_stack **stack, t_stack *first_node, int id);
t_stack	*ft_get_next_move(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
void	ft_small_to_top(t_stack **stack);
// Ft_Atol
long	ft_atol(const char *str);

#endif
