#include "basic_tests.h"
#include <string.h>

int	short_test(void)
{
	if (ft_strlen("a") == strlen("a"))
		return (0);
	else
		return (-1);
}
