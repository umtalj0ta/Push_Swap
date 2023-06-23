#include "push_swap.h"

//THE FIRST NODE IS THE FIRST ELEMENT OF THE STACK

lnk_list *create_new_node(int content)
{
    lnk_list *node;

    node = malloc(sizeof(lnk_list));
    if(!node)
        return (NULL);
    node->data = content;
    node->index = 0;
	node->position = -1;
	node->target_position = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	node->next = NULL;
    return(node);
}

void   print_list_index(lnk_list *stack)
{
    //node *iterator = stack;
    
    while(stack->next != NULL)
    {
        printf("%i\n", stack->index);
        stack = stack->next;
    }
    printf("%i\n", stack->data);
}

lnk_list    *get_last_node(lnk_list **stack)
{
    lnk_list *iterator;
    iterator = *stack;
    while(stack && iterator ->next)
    {
        iterator = iterator->next;
    }
    return(iterator);
}

void	free_stack(lnk_list **stack)
{
	lnk_list	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
