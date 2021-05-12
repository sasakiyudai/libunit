#include "atoi_tests.h"
#include <string.h>

int	bigger_str_test_atoi(void)
{
	if (ft_atoi("4242424242424242424242") == atoi("4242424242424242424242"))
		return (0);
	else
		return (-1);
}
