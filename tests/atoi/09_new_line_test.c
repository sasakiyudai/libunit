#include "atoi_tests.h"
#include <string.h>

int	new_line_test_atoi(void)
{
	if (ft_atoi("          31") == atoi("          31"))
		return (0);
	else
		return (-1);
}
