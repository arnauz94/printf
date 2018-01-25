/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:50:49 by avinas            #+#    #+#             */
/*   Updated: 2018/01/04 20:00:38 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(char *src)
{
	char	*ret;
	int		cpt;
	int		length;

	if (!src)
		return (NULL);
	length = ft_strlen(src);
	if (length == 0)
		return (src);
	cpt = 0;
	if (!(ret = (char*)malloc(sizeof(char) * length + 1)))
		return (NULL);
	while (src[cpt])
	{
		ret[length - cpt - 1] = src[cpt];
		cpt++;
	}
	ret[length] = '\0';
	return (ret);
}
