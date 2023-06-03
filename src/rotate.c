#include "push_swap.h"
/*
AQUI VAO AS FUNCOES DE ROTATION
RA
RB
RRR
*/

void    rotate_elements(lnk_list **stack)
{
 
    lnk_list	*tmp;
	lnk_list	*tmp_last;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp_last = get_last_node(*stack);
	tmp->next = NULL;
	tmp_last->next = tmp;

}
