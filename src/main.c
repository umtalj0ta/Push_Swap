#include "push_swap.h"

//THE FIRST NODE ON THE LIST IS THE FIRST ELEMENT OF THE STACK

int main(int argc, char *argv[])
{
    lnk_list    *stackA = NULL;
    lnk_list    *stackB = NULL;

    if(argc == 1)
    {
        return(printf("already sorted"));
    }

    if(argc > 2)
    {
        int i;

        i = 1;
        while(argv[i] != NULL)
        {
            int conversion = atoi(argv[i]);
            //printf("%i %i\n", i, conversion);
            lnk_list *new_node = create_new_node(conversion);
            add_to_stack(&stackA, new_node);
            i++;
        }
    }
    ft_pb(&stackA, &stackB);
    print_list_data(stackA);
    print_list_data(stackB);
}

