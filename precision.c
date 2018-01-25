#include <stdlib.h>
#include "libft/libft.h"

char	*precision_s(char *str, int precision)
{
	char *ret;
	int cpt;
	int len;

	len = ft_strlen(str);
	cpt = 0;
	if (len <= precision)
	{
		return (str);
	}
	if (!(ret = (char*)malloc(sizeof(char)*(len + 1))))
		return (NULL);
	while(cpt < precision)
	{
		ret[cpt] = str[cpt];
		cpt++;
	}
	ret[cpt] = '\0';
	return (ret);
}
