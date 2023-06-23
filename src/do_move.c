/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:44:48 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/06/23 16:44:49 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* do_rev_rotate_both:

Roda ambos os stacks A e B em sentido anti-horário até que um deles esteja na posição correta.
O custo fornecido é negativo, uma vez que ambas as posições estão na metade inferior
de seus respectivos stacks. O custo é aumentado à medida que os stacks são
rodados, quando um deles atinge 0, o stack foi rodado o máximo possível
e a posição superior está correta.
*/
static void	do_rev_rotate_both(lnk_list **a, lnk_list **b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr(a, b);
	}
}

/* ft_rotate_both:
*	Rotates both stack A and B until one of them is in position.
*	The given cost is positive since both positions are in the top half
*	of their respective stacks. The cost is decreased as the stacks are
*	rotated, when one reaches 0, the stack has been rotated as far as possible
*	and the top position is correct.
*/
static void	do_rotate_both(lnk_list **a, lnk_list **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr(a, b);
	}
}

/* do_rotate_a:
*	Rotates stack A until it is in position. If the cost is negative,
*	the stack will be reverse rotated, if it is positive, it will be 
*	rotated.
*/
static void	do_rotate_a(lnk_list **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rra(a);
			(*cost)++;
		}
	}
}

/* ft_rotate_b:
*	Rotates stack B until it is in position. If the cost is negative,
*	the stack will be reverse rotated, if it is positive, it will be 
*	rotated.
*/
static void	do_rotate_b(lnk_list **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rrb(b);
			(*cost)++;
		}
	}
}

/* do_move:
*	Chooses which move to make to get the B stack element to the correct
*	position in stack A.
*	If the costs of moving stack A and B into position match (i.e. both negative
*	of both positive), both will be	rotated or reverse rotated at the same time.
*	They might also be rotated separately, before finally pushing the top B element
*	to the top stack A.
*/
void	do_move(lnk_list **a, lnk_list **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	ft_pa(a, b);
}