#include "basic_tests.h"
#include <string.h>

int	null_test(void)
{
	if (ft_strlen("") == strlen(""))
		return (0);
	else
		return (-1);
}
