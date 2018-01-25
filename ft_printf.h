#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define MALLCHECK(x) if (!x) return (-1);

typedef	struct		s_args
{
	int				minus;
	int				plus;
	int				sharp;
	int				space;
	int				zero;
	int				size;
	int				precision;
	int				per_cent;
	char			*convert;
	char			type;
	char			*valu;
}					t_args;

int		ft_printf(const char *format, ...);
t_args	read_flag_and_field(char **arg, t_args args);
t_args	read_precision(char **arg, t_args args);
t_args	read_convert(char **arg, t_args args);
t_args	read_type_and_valu(char **arg, t_args args, va_list ap);
char	*ft_minfright(char *str, int size, char c);
char	*ft_minf(char *str, int size, char c);
char	*precision_s(char *str, int precision);
t_args	handling_minf_plus(t_args args);
t_args	handling_precision(t_args args);
char	*convert_di(t_args args, va_list ap);
char	*convert_ouxx(t_args args, va_list ap);
char	*ft_itoabig(long long n);
char	*ft_itoaubig(long long n);
char	*to_string(char *format, t_args args);

#endif

