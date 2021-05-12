#include "atoi_tests.h"
#include <string.h>

int	bus_str_test_atoi(void)
{
	if (ft_atoi("114514") == atoi("114514"))
		return (0);
	else
		return (-1);
}
