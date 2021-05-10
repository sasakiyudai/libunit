#include "basic_tests.h"
#include <string.h>

int	bus_str_test(void)
{
	if (ft_strlen("bus") == strlen("bus"))
		return (0);
	else
		return (-1);
}
