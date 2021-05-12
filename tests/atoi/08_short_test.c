#include "atoi_tests.h"
#include <string.h>

int	short_test_atoi(void)
{
	if (ft_atoi("48928492") == atoi("48928492"))
		return (0);
	else
		return (-1);
}
