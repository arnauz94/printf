/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:07:54 by avinas            #+#    #+#             */
/*   Updated: 2018/01/18 17:38:20 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

char	*convert_di(t_args args, va_list ap)
{
	if (!ft_strcmp(args.convert, "hh"))
		return (ft_itoa((char)va_arg(ap, int)));
	if (!ft_strcmp(args.convert, "h"))
		return (ft_itoa((short)va_arg(ap, int)));
	if (!ft_strcmp(args.convert, "l"))
		return (ft_itoabig(va_arg(ap, long)));
	if (!ft_strcmp(args.convert, "ll"))
		return (ft_itoabig(va_arg(ap, long long)));
	if (!ft_strcmp(args.convert, "j"))
		return (ft_itoabig(va_arg(ap, long long)));
	if (!ft_strcmp(args.convert, "z"))
		return (ft_itoabig(va_arg(ap, long long)));
	return (ft_itoa(va_arg(ap, int)));
}

char	*convert_ouxx(t_args args, va_list ap)
{
	if (!ft_strcmp(args.convert, "hh"))
		return (ft_itoa((char)va_arg(ap, unsigned int)));
	if (!ft_strcmp(args.convert, "h"))
		return (ft_itoa((short)va_arg(ap, unsigned int)));
	if (!ft_strcmp(args.convert, "l"))
		return (ft_itoabig(va_arg(ap, unsigned long)));
	if (!ft_strcmp(args.convert, "ll"))
		return (ft_itoabig(va_arg(ap, unsigned long long)));
	if (!ft_strcmp(args.convert, "j"))
		return (ft_itoabig(va_arg(ap,unsigned long long)));
	if (!ft_strcmp(args.convert, "z"))
		return (ft_itoabig(va_arg(ap, unsigned long long)));
	return (ft_itoa(va_arg(ap, int)));
}

