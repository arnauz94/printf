/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:32:25 by anaroste          #+#    #+#             */
/*   Updated: 2017/11/19 23:30:10 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		nbr;
	int		neg;
	int		i;

	i = 0;
	neg = 0;
	nbr = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || str[i] == 32)
		i++;
	if (str[i] == '-')
		neg = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i]) && ((str[i] >= '0') && (str[i] <= '9')))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if (neg == 1)
		nbr *= -1;
	return (nbr);
}
