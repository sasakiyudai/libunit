#include "atoi_tests.h"
#include <string.h>

int	num_test_atoi(void)
{
	if (ft_atoi("22222222222222") == atoi("22222222222222"))
		return (0);
	else
		return (-1);
}
