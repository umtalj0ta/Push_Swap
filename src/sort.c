#include "push_swap.h"

void    *sort_three(lnk_list **stack)
{
    lnk_list    *biggest;

    biggest = find_biggest(*stack);
    if (biggest == *stack)
        ft_ra(stack);
    else if(biggest == (*stack)->next) 
        ft_rra(stack);
    if(*stack && (*stack)->next && (*stack)->data > (*stack)->next->data)    
        ft_sa(stack);   
    return (biggest); 
}
