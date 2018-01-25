#include <stdlib.h>
#include "./libft/libft.h"

char	*ft_minfright(char *str, int size, char c)
{
	char *ret;
	int len;
	int cpt;

	cpt = 0;
	len = (int)ft_strlen(str);

	if (size <= len)
	{
		return (str);
	}
	if (!(ret = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (cpt < len)
	{
		ret[cpt] = str[cpt];
		cpt++;
	}
	while (cpt < size)
	{
		ret[cpt] = c;
		cpt++;
	}
	ret[cpt] = '\0';
	return (ret);
}

char	*ft_minf(char *str, int size, char c)
{
	char *ret;
	int len;
	int cpt;
	int cptstr;

	cptstr = 0;
	cpt = 0;
	len = (int)ft_strlen(str);
	if (size <= len)
	{
		return (str);
	}
	if (!(ret = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (cpt < size - len)
	{
		ret[cpt] = c;
		cpt++;
	}
	while (cpt < size)
	{
		ret[cpt] = str[cptstr];
		cptstr++;
		cpt++;
	}
	ret[cpt] = '\0';
	return (ret);
}
