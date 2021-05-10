#include "basic_tests.h"
#include <string.h>

int	escapes_test(void)
{
	if (ft_strlen("\t\r\n\f") == strlen("\t\r\n\f"))
		return (0);
	else
		return (-1);
}
