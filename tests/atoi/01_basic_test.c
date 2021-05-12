#include "atoi_tests.h"
#include <string.h>

int	basic_test_atoi(void)
{
	if (ft_atoi("1234") == atoi("1234"))
		return (0);
	else
		return (-1);
}
