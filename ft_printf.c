#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

void		testread(t_args a)
{
	printf("\n\n- : %d\n", a.minus);
	printf("+ : %d\n", a.plus);
	printf("# : %d\n", a.sharp);
	printf("space : %d\n", a.space);
	printf("0 : %d\n", a.zero);
	printf("size : %d\n", a.size);
	printf("precision : %d\n", a.precision);
	printf("convert : %s\n", a.convert);
	printf("type : %c\n", a.type);
	printf("valu : %s\n", a.valu);
}

t_args		init_args(t_args args)
{

	args.minus = 0;
	args.plus = 0;
	args.sharp = 0;
	args.space = 0;
	args.zero = 0;
	args.size = 0;
	args.precision = -1;
	args.per_cent = 0;
	args.convert = "";
	args.type = 0;
	args.valu = NULL;

	return (args);
}

int     ft_printf(const char *format, ...)
{
	char	*arg;
	char	*ret;
	t_args	args;
	va_list ap;

	va_start(ap, format);
	arg = (char*)format;
	ret = (char*)format;
	while ((arg = ft_strchr(arg, '%')))
	{
		args = init_args(args);
		args = read_flag_and_field(&arg, args);
		args = read_precision(&arg, args);
		args = read_convert(&arg, args);
		args = read_type_and_valu(&arg, args, ap);
		args = handling_precision(args);
		args = handling_minf_plus(args);
		ret = to_string(ret, args);
		arg = ret;
	}
	printf("%s", ret);
	va_end(ap);
	return (0);
}
