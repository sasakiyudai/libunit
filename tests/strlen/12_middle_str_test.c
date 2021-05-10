#include "basic_tests.h"
#include <string.h>

int	middle_str_test(void)
{
	if (ft_strlen("0123456789012345678901234567890\
	1234567890123456789") == strlen("0123456789012\
	3456789012345678901234567890123456789"))
		return (0);
	else
		return (-1);
}
