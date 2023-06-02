/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxfun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:48:44 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/05/01 11:23:58 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(unsigned int n, unsigned int base)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n /= base;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		i;

	i = ft_nbrlen(n, 10);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if ((!str))
		return (NULL);
	str[i--] = '\0';
	while (n)
	{
		str[i--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

int	ft_printuns(int n)
{
	int					len;
	unsigned long int	nb;
	char				*nbr;

	nb = (unsigned long int)n;
	len = 0;
	if (nb == 0)
	{
		ft_printchar('0');
		return (1);
	}
	nbr = ft_uitoa(nb);
	len += ft_printstr(nbr);
	free(nbr);
	return (len);
}
