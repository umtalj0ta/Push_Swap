/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:44:55 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/06/23 16:44:56 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

// TO DO
// verificar max int e min int
//terminar 


int    repeated_number(int* matrix, int nbr, int tamanhoMatrix)
{
    
    int j;
    int count_repeat = 0;
    
    j = 0;

    while(j < tamanhoMatrix)
    {
       if(matrix[j] == nbr)
       {
        count_repeat += 1;
       } 
       if (count_repeat == 2)
       {
            ft_printf("saiu");
            exit (1);
       }    
       j++;
    }
    return (0);
}

void  check_sintax(int* matrix, int tamanhoMatrix)
{
    int i;

    i = 0;
    while (i > tamanhoMatrix)
    {
        if (matrix[i] < '1' || matrix[i] > '9' )
            exit(1);
    }
}  