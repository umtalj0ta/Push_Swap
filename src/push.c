/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:45:09 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/06/28 12:44:59 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
aQUI VAO AS FUNCOES DE PUSH
PA
PB*/

#include "push_swap.h"

void push_element(lnk_list **stacka, lnk_list **stackb)
{
    lnk_list *tmp;

    if (*stacka == NULL)
        return ;
    tmp = *stacka;
    *stacka = (*stacka)->next;
    tmp->next = *stackb;
    *stackb = tmp;
}

void ft_pa(lnk_list **stacka, lnk_list **stackb)
{
    push_element(stackb, stacka);
    ft_printf("pa\n");
}
void ft_pb(lnk_list **stacka, lnk_list **stackb)
{
    push_element(stacka, stackb);
    ft_printf("pb\n");
}
