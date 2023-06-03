#include "push_swap.h"

//THE FIRST NODE IS THE FIRST ELEMENT OF THE STACK

lnk_list *create_new_node(int content)
{
    lnk_list *node;

    node = malloc(sizeof(node));
    if(!node)
        return (NULL);
    node->data = content;
    node->next = NULL;
    return(node);
}

// void    add_to_stack(node *stack, node *new_node)
// {
//     node *iterator = stack;
//     if(!stack)
//         return;
//     while(iterator->next != NULL)
//     {
//         iterator= iterator->next;
//     }

//     iterator->next = new_node;
// }    

void    add_to_stack(lnk_list **stack, lnk_list *new_node)
{
    lnk_list *iterator;

    if(!stack)
        return ; 
    if(!*stack)
        *stack = new_node;
    else
    {   iterator= *stack;       
        while(iterator->next != NULL)
            iterator = iterator->next;
        iterator->next = new_node;    
    }
}    

void   print_list_data(lnk_list *stack)
{
    //node *iterator = stack;
    
    while(stack->next != NULL)
    {
        printf("%i\n", stack->data);
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