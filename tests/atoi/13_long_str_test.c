#include "atoi_tests.h"
#include <string.h>

int	long_str_test_atoi(void)
{
	if (ft_atoi("01234567890123456789012345678901234567890123456789") == \
	atoi("01234567890123456789012345678901234567890123456789"))
		return (0);
	else
		return (-1);
}
