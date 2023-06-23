/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:15:24 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/06/23 16:45:23 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

lnk_list *find_biggest(lnk_list *stack)
{
    if(!stack)
        return NULL;
    lnk_list *biggest;

    biggest = stack;
    while(stack)
    {
        if(stack->data > biggest ->data)
            biggest= stack;
        stack = stack->next;  
    }
    return(biggest);
}
lnk_list *find_second_biggest(lnk_list *stack) 
{
    if (!stack || !stack->next)
        return NULL;

    lnk_list* biggest = stack;
    lnk_list* secondBiggest = stack;

    while (stack) 
    {
        if (stack->data > biggest->data) 
        {
            secondBiggest = biggest;
            biggest = stack;
        } else if (stack->data > secondBiggest->data && stack->data < biggest->data)
        {
            secondBiggest = stack;
        }
        stack = stack->next;
    }

    return secondBiggest;
}

int is_sorted(lnk_list *stack) 
{
    lnk_list    *current;
    if (stack == NULL || stack->next == NULL) {
        return 1; // Empty list or single element, considered sorted
    }

    current = stack;
    while (current->next != NULL) {
        if (current->data > current->next->data) {
            return 0; // Found out-of-order elements
        }
        current = current->next;
    }

    return 1; // All elements are in ascending order
}

lnk_list *find_smallest(lnk_list *stack)
{
    if(!stack)
        return NULL;
    lnk_list    *smallest;

    smallest = stack;
    while(stack)
    {
        if(stack->data < smallest ->data)
            smallest = stack;
        stack = stack->next;          
    }  
    return(smallest);  
}