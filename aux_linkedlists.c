#include "push_swap.h"

//THE FIRST NODE IS THE FIRST ELEMENT OF THE STACK

node *create_new_node(int content)
{
    node *node;

    node = malloc(sizeof(node));
    if(!node)
        return (NULL);
    node->data = content;
    node->next = NULL;

    return(node);
}

void    add_to_stack(node *stack, node *new_node)
{
    node *iterador = stack;
    while(iterador->next != NULL)
    {
        iterador= iterador->next;
    }

    iterador->next = new_node;
}    

void   print_list_data(node *stack)
{
    node *iterador = stack;
    
    while(iterador->next != NULL)
    {
        printf("%i\n", iterador->data);
        iterador = iterador->next;
    }
    printf("%i\n", iterador->data);
}
