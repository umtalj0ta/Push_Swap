/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:24:53 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/05 20:47:18 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

lnk_list	*swap_init(int argc, char *argv[])
{
	lnk_list	*stack_a;
	int			conversion;
	int			i;
	lnk_list	*new_node;

	stack_a = NULL;
	if (argc >= 2)
	{
		i = 1;
		while (argv[i] != NULL)
		{
			conversion = atoi(argv[i]);
			new_node = create_new_node(conversion);
			add_to_stack(&stack_a, new_node);
			i++;
		}
	}
	return (stack_a);
}

static void	push_swap(lnk_list **stack_a, lnk_list **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		ft_sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	int			stack_size;
	lnk_list	*stack_a;
	lnk_list	*stack_b;

	if (argc < 2)
		return (0);
	if (!is_correct_input(argv))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	check_integer_range(argv, argc);
	stack_a = swap_init(argc, argv);
	stack_b = swap_init(0, 0);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
