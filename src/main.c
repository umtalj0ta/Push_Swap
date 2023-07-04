/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:24:53 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/04 15:25:26 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//THE FIRST NODE ON THE LIST IS THE FIRST ELEMENT OF THE STACK
 int    error_handling(char **argv, int argc)
{
   char** matrix;
    int i;
    int nbr;
   int* matrix_int;
    
    i = 0;
    nbr = 0;
    // Determinar tamanho matriz. 
    if(argc < 2)
    {
        printf("You should do like ./push_swap <2 4 5 6 7>");
        exit(1);
    }
    if(argc == 2 && !argv[1][0])
        exit(1);
    if(argc == 2)
    {
        // Dividir argv em arrays de strings (ou matriz de string).
        matrix = ft_split(argv[1], ' ');
        int tamanhoMatriz = 0;
        while(matrix[i] != NULL)
        {
            tamanhoMatriz++;
            i++;
        }
        // Converter matriz de strings em array de inteiros.
        matrix_int = malloc(sizeof(int) * tamanhoMatriz + 1);
        matrix_int[tamanhoMatriz + 1] = 0;
        i = 0;
        while( i < tamanhoMatriz )
        {
            //mudar para atol
            matrix_int[i] = ft_atoi(matrix[i]);
            i++;
        }
        // Verificar existência de números repetidos.
        i = 0;
        while( i < tamanhoMatriz)
        {
            repeated_number(matrix_int, matrix_int[i], tamanhoMatriz);
            check_sintax(matrix_int, tamanhoMatriz);
            i++;
        }
        
    }
    if (argc >= 2)
    {
        while(argv[i])
        {
            nbr = ft_atoi(argv[i]);
             repeated_number((int*) argv, nbr, argc - 1);
             //check_sintax(argv, argv[i]);
            i++;
        }
    }
    return 0;   
}

lnk_list *swap_init(int argc, char *argv[])
{
    lnk_list* stackA = NULL;
    //lnk_list    *stackB = NULL;
    char**      argument_count2;
    int conversion;
    
    if(argc == 2)
    {
        int k;

        k = 1;
        argument_count2 = ft_split(argv[1], ' ');
        while(argument_count2[k] != NULL)
        {
            conversion = atoi(argument_count2[k]);
            lnk_list *new_node = create_new_node(conversion);
            add_to_stack(&stackA, new_node);
            k++;
        }
    }
    if(argc >= 2)
    {
        int i;

        i = 1;
        while(argv[i] != NULL)
        {
            conversion = atoi(argv[i]);
            lnk_list *new_node = create_new_node(conversion);
            add_to_stack(&stackA, new_node);
            i++;
        }
    }
    //ft_rra(&stackA);
    //ft_printf("\n");
    //print_list_data(stackB);
    return stackA;
}

static void	push_swap(lnk_list **stack_a, lnk_list **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		ft_sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int main(int argc, char *argv[])
{
    int stack_size;
    
    error_handling(argv,argc);
    lnk_list *stackA = swap_init(argc, argv);
    lnk_list *stackB = swap_init(0,0);
    stack_size = get_stack_size(stackA);
    assign_index(stackA, stack_size + 1);
    push_swap(&stackA, &stackB, stack_size);

    // print_list_data(stackA);
    free_stack(&stackA);
    free_stack(&stackB);

    return 0;
}

