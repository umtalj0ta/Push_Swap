/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:29:33 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/06/23 10:39:53 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
# include "../printf/ft_printf.h"
typedef struct s_list
{
    int data;
    struct s_list *next;
    struct s_list *prev;
} lnk_list ;

//adicionar index
// target node 
// posicao na metade
// preco 
// bool cheapeast
// prev 
// index final 


lnk_list * create_new_node(int content);
void   print_list_data(lnk_list *stack);
void    add_to_stack(lnk_list **stack, lnk_list *new_node);
void    swap_elements(lnk_list *stack);
void    ft_sa(lnk_list **stackA);
void    ft_sb(lnk_list **stackB);
void    ft_ss(lnk_list **stackA, lnk_list **stackB);
void    rotate_elements(lnk_list **stack);
void    ft_ra(lnk_list **stackA);
void    ft_rb(lnk_list **stackB);
void    ft_rr(lnk_list **stackA, lnk_list **stackB);
void    reverse_rotate(lnk_list **stack);
void    ft_rra(lnk_list **stackA);
void    ft_rrb(lnk_list **stackB);
void    ft_rrr(lnk_list **stackA, lnk_list **stackB);
void    push_element(lnk_list **stacka, lnk_list **stackb);
void    ft_pa(lnk_list **stackA, lnk_list **stackB);
void    ft_pb(lnk_list **stackA, lnk_list **stackB);
int    repeated_number(int* matrix, int nbr, int tamanhoMatrix);
void  check_sintax(int* matrix, int tamanhoMatrix);
lnk_list *find_biggest(lnk_list *stack);
lnk_list *find_second_biggest(lnk_list *stack) ;
lnk_list *find_smallest(lnk_list *stack);
void    *sort_three(lnk_list **stack);
void sort_five(lnk_list **stackA, lnk_list **stackB);
int is_sorted(lnk_list *stack);
