#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

char	*addplus(char *str)
{
	char	*ret;
	int		len;
	int		cpt;

	cpt = 0;
	len = ft_strlen(str);
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[0] = '+';
	while(cpt < len)
	{
		ret[cpt + 1] = str[cpt]; 
		cpt++;
	}
	ret[cpt + 1] = '\0';
	return (ret);
}

char	*remove_minus_minf(char *str, int size)
{
	char	*ret;
	int		len;
	int		cpt;

	cpt = 0;
	len = ft_strlen(str);
	if (len >= size)
		return (str);
	if (!(ret = (char*)malloc(sizeof(char) * (len - 1))))
		return (NULL);

	while(cpt < len)
	{
		ret[cpt] = str[cpt + 1]; 
		cpt++;
	}
	ret[cpt] = '\0';
	ret = ft_minf(ret, size, '0');
	ret[0] = '-';
	return (ret);
}

t_args		handling_precision(t_args args)
{
	if (args.precision)
	{
		if (args.type == 's' || args.type == 'S' || args.type == 'c')
		{
			if (args.precision != -1)
				args.valu = precision_s(args.valu, args.precision);
		}
		else if (args.type == 'd' || args.type == 'i' || args.type == 'u')
		{
			if (args.valu[0] == '-')
				args.valu = remove_minus_minf(args.valu, args.precision + 1);
			else
				args.valu = ft_minf(args.valu, args.precision, '0');
		}
	}
	return (args);
}

t_args		handling_minf_plus(t_args args)
{
	char	c;

	if (args.zero && !args.minus)
		c = '0';
	else
		c = ' ';
	if (args.plus && c == ' ' && (args.type == 'd' || args.type == 'i' || args.type == 'D' || args.type == 'u'))
	{
		if (args.valu[0] != '-')
			args.valu = addplus(args.valu);
	}
	if (args.size)
	{
		if (args.minus)
		{
			args.valu = ft_minfright(args.valu, args.size, c);
		}
		else
		{
			if (args.precision >= 0)
				c = ' ';
			if ((args.type == 'd' || args.type == 'i' || args.type == 'D') && args.valu[0] == '-' && c == '0')
			{
				args.valu = remove_minus_minf(args.valu, args.size);
			}
			else
				args.valu = ft_minf(args.valu, args.size, c);

		}
	}
	if (args.plus && c == '0' && (args.type == 'd' || args.type == 'i' || args.type == 'D' || args.type == 'u'))
	{
		if (args.precision >= 0)
			c = ' ';
		if (args.valu[0] != '-')
			args.valu[0] = '+';
	}
	return (args);
}
