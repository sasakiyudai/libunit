#include "atoi_tests.h"
#include <string.h>

int	shinji_test_atoi(void)
{
	if (ft_atoi("") == atoi(""))
		return (0);
	else
		return (-1);
}
