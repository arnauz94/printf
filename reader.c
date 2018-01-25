/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:10:50 by avinas            #+#    #+#             */
/*   Updated: 2018/01/25 15:12:48 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

t_args		read_flag_and_field(char **arg, t_args args)
{
	*arg = *arg + 1;
	while (**arg == '-' || **arg == '+' || **arg == '#' 
			|| **arg == ' ' || **arg == '0')
	{
		if (**arg == '-')
			args.minus = 1;
		if (**arg == '+')
			args.plus = 1;
		if (**arg == '#')
			args.sharp = 1;
		if (**arg == ' ')
			args.space = 1;
		if (**arg == '0')
			args.zero = 1;
		*arg = *arg + 1;
	}
	if (ft_isdigit(**arg) && **arg != '0')
	{
		args.size = ft_atoi(*arg);
		while (ft_isdigit(**arg))
			*arg = *arg + 1;
	}
	return (args);
}

t_args		read_precision(char **arg, t_args args)
{
	if (**arg == '.')
	{
		*arg = *arg + 1;
		if (ft_isdigit(**arg))
		{
			args.precision = ft_atoi(*arg);
			while (ft_isdigit(**arg))
				*arg = *arg + 1;
		}

	}
	return (args);
}

t_args		read_convert(char **arg, t_args args)
{
	if (**arg == 'h')
	{
		*arg = *arg + 1;
		if (**arg == 'h')
			args.convert = "hh";
		else
		{
			args.convert = "h";
			*arg = *arg - 1;
		}
	}
	if (**arg == 'l')
	{
		*arg = *arg + 1;
		if (**arg == 'l')
			args.convert = "ll";
		else
		{
			args.convert = "l";
			*arg = *arg - 1;
		}
	}
	if (**arg == 'j')
		args.convert = "j";
	if (**arg == 'z')
		args.convert = "z";
	if (ft_strcmp(args.convert, ""))
	{
		*arg = *arg + 1;
	}
	return (args);
}

t_args		read_type_and_valu(char	**arg, t_args args, va_list ap)
{
	char	c;

	args.type = **arg;
	*arg = *arg + 1;
	if (args.type == 's' || args.type == 'S')
		args.valu = va_arg(ap, char*);
	if (args.type == 'p')
		args.valu = va_arg(ap, void*);
	if (args.type == 'o' || args.type == 'u' ||
		args.type == 'x' || args.type == 'X')
		args.valu = convert_ouxx(args, ap);
	if (args.type == 'd' || args.type == 'i')
   		args.valu = convert_di(args, ap);
	if (args.type == 'c' || args.type == 'C')
	{
		c = (char)va_arg(ap, int);
		args.valu = ft_strnew(1);
		args.valu[0] = c;
	}
	if (args.type == 'D')
		args.valu = ft_itoa(va_arg(ap, long int));


	return (args);
}
