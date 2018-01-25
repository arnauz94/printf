#include "libft/libft.h"
#include "ft_printf.h"


char    *to_string(char *format, t_args args)
{
	size_t  beginarg;
	size_t  endarg;
	size_t  lenarg;
	size_t  cpt;
	size_t  cptvalu;
	size_t  cptarg;
	char    *ret;

	cpt = 0;
	cptarg = 0;
	cptvalu = 0;
	beginarg = ft_strlen(format) - ft_strlen(ft_strchr(format, '%'));
	cpt = beginarg;
	while (format[cpt] != 's' && format[cpt] != 'S' && format[cpt] != 'p' &&
			format[cpt] != 'o' && format[cpt] != 'u' && format[cpt] != 'x' &&
			format[cpt] != 'X' && format[cpt] != 'd' && format[cpt] != 'i' &&
			format[cpt] != 'c' && format[cpt] != 'C')
	{
		cpt++;
	}
	endarg = cpt;
	lenarg = endarg - beginarg + 1;
	ret = ft_strnew(ft_strlen(format) + ft_strlen(args.valu)  - lenarg);
	cpt = 0;
	while (cpt < ft_strlen(format))
	{
		if (cpt == beginarg)
		{
			while (cptvalu < ft_strlen(args.valu))
			{
				ret[cptarg] = args.valu[cptvalu];
				cptarg++;
				cptvalu++;
			}
		}

		if (cpt < beginarg || cpt > endarg)
		{
			ret[cptarg] = format[cpt];
			cptarg++;
		}
		cpt++;
	}

	ret[cptarg] = '\0';
	return (ret);
}
