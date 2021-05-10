#include "basic_tests.h"
#include <string.h>

int	new_line_test(void)
{
	if (ft_strlen("\n") == strlen("\n"))
		return (0);
	else
		return (-1);
}
