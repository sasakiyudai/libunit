#include "atoi_tests.h"
#include <string.h>

int	hello_test_atoi(void)
{
	if (ft_atoi("+1") == atoi("+1"))
		return (0);
	else
		return (-1);
}
