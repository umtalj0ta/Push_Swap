/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:44:55 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/05 20:29:41 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	check_repeated(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i])
	{
		j = i + 1;
		while (arg[j])
		{
			if (ft_strcmp(arg[i], arg[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*remove_leading_zeros(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] == '0')
		i++;
	if (!s[i])
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	else
	{
		if (s[0] == '-')
			s[j++] = '-';
		while (s[i])
			s[j++] = s[i++];
		s[j] = '\0';
		return (s);
	}
}

int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] && !(s[i] >= '0' && s[i] <= '9'))
		return (0);
	if (!s[i] && ((s[i - 1] == '+' || (s[i - 1] == '-'))))
		return (0);
	return (1);
}

int	is_correct_input(char **arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (!is_valid_number(arg[i]))
			return (0);
		if (arg[i][0] == '0' || arg[i][1] == '0')
			arg[i] = remove_leading_zeros(arg[i]);
		i++;
	}
	if (check_repeated(arg) || !arg[1][0])
		return (0);
	return (1);
}

int	check_integer_range(char **argv, int argc)
{
	long	num;
	int		i;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (1);
}
