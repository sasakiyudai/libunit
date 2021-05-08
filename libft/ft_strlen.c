#include "libft.h"

int ft_strlen(char *s)
{
	int i;

	while (s[i])
		i++;
	return (i);
}