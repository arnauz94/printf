/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:52:55 by avinas            #+#    #+#             */
/*   Updated: 2017/12/22 17:54:53 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *p1, const void *p2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)p1)[i] != ((unsigned char *)p2)[i])
			return (((unsigned char *)p1)[i] - ((unsigned char *)p2)[i]);
		i++;
	}
	return (0);
}
