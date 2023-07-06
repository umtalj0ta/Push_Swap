/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:29:33 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/06 13:05:19 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../printf/ft_printf.h"
# include "stdbool.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	int				position;
	int				target_position;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void				print_list_data(t_list *stack);
void				add_to_stack(t_list **stack, t_list *new_node);
void				swap_elements(t_list *stack);
void				ft_sa(t_list **stackA);
void				ft_sb(t_list **stackB);
void				ft_ss(t_list **stackA, t_list **stackB);
void				rotate_elements(t_list **stack);
void				ft_ra(t_list **stackA);
void				ft_rb(t_list **stackB);
void				ft_rr(t_list **stackA, t_list **stackB);
void				reverse_rotate(t_list **stack);
void				ft_rra(t_list **stackA);
void				ft_rrb(t_list **stackB);
void				ft_rrr(t_list **stackA, t_list **stackB);
void				push_element(t_list **stacka, t_list **stackb);
void				ft_pa(t_list **stackA, t_list **stackB);
void				ft_pb(t_list **stackA, t_list **stackB);
int					is_correct_input(char **arg);
t_list				*find_biggest(t_list *stack);
t_list				*find_second_biggest(t_list *stack);
t_list				*find_smallest(t_list *stack);
void				*sort_three(t_list **stack);
// void sort_five(t_list **stackA, t_list **stackB);
int					is_sorted(t_list *stack);
int					get_stack_size(t_list *stack);
int					check_integer_range(char **argv, int argc);
void				assign_index(t_list *stacka, int stack_size);
void				free_stack(t_list **stack);
void				sort(t_list **stack_a, t_list **stack_b);
void				do_cheapest_move(t_list **stack_a, t_list **stack_b);
void				get_cost(t_list **stack_a, t_list **stack_b);
void				do_move(t_list **a, t_list **b, int cost_a, int cost_b);
int					get_lowest_index_position(t_list **stack);
void				get_target_position(t_list **a, t_list **b);
long int			ft_atol(char *npr);
int					ft_strcmp(char *s1, char *s2);
// static void	do_rotate_a(t_list **a, int *cost);
int					nb_abs(int nb);
t_list				*create_new_node(int content);
// static void	get_position(t_list **stack);

#endif