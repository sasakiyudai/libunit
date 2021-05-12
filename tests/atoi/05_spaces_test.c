#include "atoi_tests.h"
#include <string.h>

int	spaces_test_atoi(void)
{
	if (ft_atoi("-9") == atoi("-9"))
		return (0);
	else
		return (-1);
}
