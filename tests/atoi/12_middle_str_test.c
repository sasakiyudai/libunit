#include "atoi_tests.h"
#include <string.h>

int	middle_str_test_atoi(void)
{
	if (ft_atoi("      -318919313818913") == atoi("      -318919313818913"))
		return (0);
	else
		return (-1);
}
