/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:24:53 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/05 16:08:00 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

lnk_list	*swap_init(int argc, char *argv[])
{
	lnk_list	*stackA;
	int			conversion;
		int i;
	lnk_list	*new_node;
	stackA = NULL;
	if (argc >= 2)
	{
		i = 1;
		while (argv[i] != NULL)
		{
			conversion = atoi(argv[i]);
			new_node = create_new_node(conversion);
			add_to_stack(&stackA, new_node);
			i++;
		}
	}
	return (stackA);
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
	lnk_list	*stackA;
	lnk_list	*stackB;

	if(argc < 2)
		return 0;	
	if(!is_correct_input(argv))
	{
		ft_putstr_fd("Error\n",2);
		exit(1);
	}
	check_integer_range(argv, argc);
	stackA = swap_init(argc, argv);
	stackB = swap_init(0, 0);
	stack_size = get_stack_size(stackA);
	assign_index(stackA, stack_size + 1);
	push_swap(&stackA, &stackB, stack_size);
	free_stack(&stackA);
	free_stack(&stackB);
	return (0);
}
