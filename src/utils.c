
#include "push_swap.h"

/* nb_abs:
*	Returns the absolute value of a given number.
*	The absolute value of a number is used to measure the distance of that
*	number from 0, whether it is positive or negative (abs value of -6 is 6).
*/
int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void print_list_data(lnk_list *stack)
{
    while (stack != NULL)
    {
        printf("%i\n", stack->data);
        stack = stack->next;
    }
}