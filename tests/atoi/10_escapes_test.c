#include "atoi_tests.h"
#include <string.h>

int	escapes_test_atoi(void)
{
	if (ft_atoi("\t\r\n\f8931") == atoi("\t\r\n\f8931"))
		return (0);
	else
		return (-1);
}
