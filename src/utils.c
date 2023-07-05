/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:45:41 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/05 16:08:30 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	print_list_data(lnk_list *stack)
{
	while (stack != NULL)
	{
		printf("%i\n", stack->data);
		stack = stack->next;
	}
}

long int	ft_atol(char *npr)
{
	long int res;
	int signal;
	int i;
	
	i = 0;
	signal = 1;
	res = 0;
	while (npr[i] == ' ' || npr[i] == '\t'
		|| npr[i] == '\n'
		|| npr[i] == '\r' || npr[i] == '\v' || npr[i] == '\f')
	i++;
	if (npr[i] == '\0')
		return (0);
	if (npr[i] == '-')
		signal *= -1;
	if (npr[i] == '-' || npr[i] == '+')
		i++;
	while (npr[i] && npr[i] >= '0' && npr[i] <= '9')
	{
		res = res * 10 + npr[i] - '0';
		i++;
	}
	return (res * signal);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (*s1 == '+')
	{
		if (*s2 != '+')
			s1++;
	}
	else
	{
		if (*s2 == '+')
			s2++;
	}
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}