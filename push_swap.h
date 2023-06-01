#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    int data;
    struct s_list *next;
} node ;

node * create_new_node(int content);
void   print_list_data(node *stack);
void    add_to_stack(node *stack, node *new_node);